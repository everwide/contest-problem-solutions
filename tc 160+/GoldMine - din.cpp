#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<class T>
vector<T> tokenize(string s, const string &delim=" ") {
  vector<T> ret;
  string::size_type i=0;
  string::size_type len = delim.length();
  if (delim != " ")
    while ((i=s.find(delim)) != string::npos)
      s.replace(i, len, " ");

  istringstream is(s);
  T val;
  while (is >> val)
    ret.push_back(val);
  return ret;
}
class GoldMine {
	public:
	int eval(const vector<int> &a, int c) {
		int ret = 0;
		for (int i=0; i<=6; ++i)
			if (i > c)
				ret += c*a[i]*60;
			else if (i == c)
				ret += a[i]*c*50;
			else
				ret += a[i]*(i*50 - (c-i)*20);
		return ret;
	}
	vector <int> getAllocation(vector <string> mines, int miners) {
		vector<vector<int> > best(mines.size()+1, vector<int>(miners+1, -1000000000));
		vector<vector<int> > from(mines.size()+1, vector<int>(miners+1, 0));
		for (int i=0; i<(int)mines.size(); ++i)
			best[i][0] = 0;


		for (int i=1; i<=(int)mines.size(); ++i) {
			vector<int> prob = tokenize<int>(mines[i-1], ", ");
			for (int j=0; j<=miners; ++j)
				for (int m=0; m<=6 && j+m<=miners; ++m) {
					const int t = eval(prob, m);
					if (best[i-1][j]+t >= best[i][j+m]) {
						best[i][j+m] = best[i-1][j]+t;
						from[i][j+m] = j;
					}
				}
		}

		vector<int> sol(mines.size(), 0);
		int cur = from[mines.size()][miners];
		for (int i=mines.size()-1; i>=0; --i) {
			sol[i] = miners - cur;
			miners = cur;
			cur = from[i][miners];
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "000, 030, 030, 040, 000, 000, 000",
  "020, 020, 020, 010, 010, 010, 010" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arr2[] = { 2,  2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getAllocation(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = { "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000",
  "100, 000, 000, 000, 000, 000, 000" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arr2[] = { 6,  2,  0,  0,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getAllocation(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = { "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000",
  "050, 000, 000, 000, 000, 050, 000" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arr2[] = { 4,  4,  4,  4,  4,  4,  4,  2,  0,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getAllocation(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = { "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004",
  "026, 012, 005, 013, 038, 002, 004" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 56; int Arr2[] = { 2,  2,  2,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getAllocation(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = { "100, 000, 000, 000, 000, 000, 000",
  "090, 010, 000, 000, 000, 000, 000",
  "080, 020, 000, 000, 000, 000, 000",
  "075, 025, 000, 000, 000, 000, 000",
  "050, 050, 000, 000, 000, 000, 000",
  "025, 075, 000, 000, 000, 000, 000",
  "020, 080, 000, 000, 000, 000, 000",
  "010, 090, 000, 000, 000, 000, 000",
  "000, 100, 000, 000, 000, 000, 000",
  "000, 090, 010, 000, 000, 000, 000",
  "000, 080, 020, 000, 000, 000, 000",
  "000, 075, 025, 000, 000, 000, 000",
  "000, 050, 050, 000, 000, 000, 000",
  "000, 025, 075, 000, 000, 000, 000",
  "000, 020, 080, 000, 000, 000, 000",
  "000, 010, 090, 000, 000, 000, 000",
  "000, 000, 100, 000, 000, 000, 000",
  "000, 000, 090, 010, 000, 000, 000",
  "000, 000, 080, 020, 000, 000, 000",
  "000, 000, 075, 025, 000, 000, 000",
  "000, 000, 050, 050, 000, 000, 000",
  "000, 000, 025, 075, 000, 000, 000",
  "000, 000, 020, 080, 000, 000, 000",
  "000, 000, 010, 090, 000, 000, 000",
  "000, 000, 000, 100, 000, 000, 000",
  "000, 000, 000, 100, 000, 000, 000",
  "000, 000, 000, 090, 010, 000, 000",
  "000, 000, 000, 080, 020, 000, 000",
  "000, 000, 000, 075, 025, 000, 000",
  "000, 000, 000, 050, 050, 000, 000",
  "000, 000, 000, 025, 075, 000, 000",
  "000, 000, 000, 020, 080, 000, 000",
  "000, 000, 000, 010, 090, 000, 000",
  "000, 000, 000, 000, 100, 000, 000",
  "000, 000, 000, 000, 090, 010, 000",
  "000, 000, 000, 000, 080, 020, 000",
  "000, 000, 000, 000, 075, 025, 000",
  "000, 000, 000, 000, 050, 050, 000",
  "000, 000, 000, 000, 025, 075, 000",
  "000, 000, 000, 000, 020, 080, 000",
  "000, 000, 000, 000, 010, 090, 000",
  "000, 000, 000, 000, 000, 100, 000",
  "000, 000, 000, 000, 000, 090, 010",
  "000, 000, 000, 000, 000, 080, 020",
  "000, 000, 000, 000, 000, 075, 025",
  "000, 000, 000, 000, 000, 050, 050",
  "000, 000, 000, 000, 000, 025, 075",
  "000, 000, 000, 000, 000, 020, 080",
  "000, 000, 000, 000, 000, 010, 090",
  "000, 000, 000, 000, 000, 000, 100" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 150; int Arr2[] = { 0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  6,  6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getAllocation(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GoldMine ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
