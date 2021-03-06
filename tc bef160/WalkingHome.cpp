#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<class T>
vector<T> tokenize(string s, const string &delim=" ")
{
    vector<T> ret_val;
    string::size_type i=0;
    string::size_type len = delim.length();
    if (delim != " ")
        while ((i=s.find(delim)) != string::npos)
            s.replace(i, len, " ");

    istringstream is(s);
    T val;

    while (is >> val)
        ret_val.push_back(val);
    return ret_val;
}
template<class T>
string to_str(T x)
{
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}

/*** real code starts here ***/
#define INFTY 30000
vector<string> m;
vector<vector<int> > best;
int kuca, skola;
int n, nn;

inline
bool inbound(int i, int j)
{
	return i>=0 && i<n && j>=0 && j<nn;
}
class WalkingHome {
	public:
	void go(int i, int j, int d)
	{
		if (best[i][j]<=d) return;
		best[i][j] = d;
		
		for (int di=-1; di<2; ++di)
			for (int dj=-1; dj<2; ++dj)
				if (abs(di)+abs(dj)==1 && inbound(i+di, j+dj)) {
					if (m[i+di][j+dj]=='.') go(i+di, j+dj, d);
					else if (m[i+di][j+dj]=='-' && dj==0) {
						int k=abs(di);
						int sign = di;
						while (inbound(i+sign*k, j) && m[i+sign*k][j]=='-')
							++k;
						if (inbound(i+sign*k, j) && m[i+sign*k][j]=='.')
							go(i+sign*k, j, d+1);
					} else if (m[i+di][j+dj]=='|' && di==0) {
						int k=abs(dj);
						int sign = dj;
						while (inbound(i, j+sign*k) && m[i][j+sign*k]=='|')
							++k;
						if (inbound(i, j+sign*k) && m[i][j+sign*k]=='.')
							go(i, j+sign*k, d+1);
					}
				}
	}
	int fewestCrossings(vector <string> map)
	{
		m = map;
		best = vector<vector<int> > (map.size(), vector<int>(map[0].size(), INFTY));
		n = m.size();
		nn = m[0].size();
		
		for (int i=0; i<n; ++i)
			for (int j=0; j<nn; ++j)
				if (m[i][j] == 'S') {
					skola = i*64+j;
					m[i][j] = '.';
				}
				else if (m[i][j] == 'H') kuca = i*64+j;
		go(kuca/64, kuca%64, 0);
		
		int sol = best[skola/64][skola%64];
		return (sol==INFTY) ? -1:sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"S.|..",
 "..|.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, fewestCrossings(Arg0)); }
	void test_case_1() { string Arr0[] = {"S.|..",
 "..|.H",
 "..|..",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, fewestCrossings(Arg0)); }
	void test_case_2() { string Arr0[] = {"S.||...",
 "..||...",
 "..||...",
 "..||..H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, fewestCrossings(Arg0)); }
	void test_case_3() { string Arr0[] = {"S.....",
 "---*--",
 "...|..",
 "...|.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, fewestCrossings(Arg0)); }
	void test_case_4() { string Arr0[] = {"S.F..",
 "..F..",
 "--*--",
 "..|..",
 "..|.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, fewestCrossings(Arg0)); }
	void test_case_5() { string Arr0[] = {"H|.|.|.|.|.|.|.|.|.|.|.|.|.",
 "F|F|F|F|F|F|F|F|F|F|F|F|F|-",
 "S|.|.|.|.|.|.|.|.|.|.|.|.|."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(5, Arg1, fewestCrossings(Arg0)); }
	void test_case_6() { string Arr0[] = {"S-H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(6, Arg1, fewestCrossings(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    WalkingHome ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
