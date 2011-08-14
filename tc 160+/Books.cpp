#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Books {
	public:
	int sortMoves(vector <string> a) {
		const int n = a.size();
		vector<vector<int> > dp(n, vector<int>(n, 0));
		vector<string> b = a;

		sort(b.begin(), b.end());

		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j) {
				int best = b[i]==a[j];
				if (i>0 && dp[i-1][j]>best)
					best = dp[i-1][j];
				if (j>0 && dp[i][j-1]>best)
					best = dp[i][j-1];
				if (i>0 && j>0 && dp[i-1][j-1]+(b[i]==a[j]) > best)
					best = dp[i-1][j-1]+(b[i]==a[j]);

				dp[i][j] = best;
			}

		return a.size() - dp[n-1][n-1];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Algorithms", "Purely Functional Data Structures",
"Intro to C", "Automata and Computability"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, sortMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {"the fellowship of the ring",
"the return of the king",
"The two towers"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, sortMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"Basic Engineering Circuit Analysis", "A Course in Combinatorics",
"Artificial Intelligence", "Asimovs Guide to Shakespeare",
"The Nature of Space and Time", "A Time for Trumpets",
"Essentials of Artificial Intelligence", "Life by the Numbers",
"Cognitive Psychology", "ColdFusion"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, sortMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {"A", "B", "A", "A", "B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, sortMoves(Arg0)); }
	void test_case_4() { string Arr0[] = {"This Book Has No Title", " This Book Does Have A Title"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, sortMoves(Arg0)); }
	void test_case_5() { string Arr0[] = {"What Is The", "What Is The ", "What Is The Title Of This Book"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(5, Arg1, sortMoves(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Books ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
