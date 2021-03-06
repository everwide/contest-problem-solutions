#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool valid(int x, int y, int m, int n) {
	if (x<0 || y<0 || x>=m || y>=n)
		return false;
	return true;
}
class Squares {
	public:
	int countSquares(vector <string> field) {
		int sol = 0;
		int m = field.size();
		int n = field[0].size();

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				for (int k=0; k<m; ++k)
					for (int l=0; l<n; ++l)
						if (i!=k || j!=l) {
							int x = k-i;
							int y = l-j;
							if (field[i][j] != field[k][l])
								continue;
							if (!valid(x-y+i, x+y+j, m, n) || field[x-y+i][x+y+j] != field[i][j])
								continue;
							if (!valid(-y+i, x+j, m, n) || field[-y+i][x+j] != field[i][j])
								continue;
							++sol;
						}

		return sol/4;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABA", "BAB", "ABA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, countSquares(Arg0)); }
	void test_case_1() { string Arr0[] = {"AA", "AA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, countSquares(Arg0)); }
	void test_case_2() { string Arr0[] = {"ABC", "DEF", "GHI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countSquares(Arg0)); }
	void test_case_3() { string Arr0[] = {"AABCA", "AAAAA", "BAAAB", "AAAEA", "ADBFA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(3, Arg1, countSquares(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Squares ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
