#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long red[61];
long long nonRed[61];
class RedundantStrings {
	public:
	int howMany(int length) {
		red[1] = 0;
		nonRed[1] = 2;

		for (int i=2; i<=length; ++i) {
			red[i] = 0;
			for (int j=1; j*j<=i; ++j)
				if (i%j == 0)
					red[i] += nonRed[j] + (i/j!=j && j!=1 ? nonRed[i/j] : 0);
			nonRed[i] = (1LL<<i)-red[i];
		}

		return red[length];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 34; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { int Arg0 = 30; int Arg1 = 33814; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RedundantStrings ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
