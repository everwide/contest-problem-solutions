#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class DivisorDigits {
	public:
	int howMany(int n) {
		int x = n;
		int sol = 0;
		while (x > 0) {
			int d = x%10;
			if (d > 0)
				sol += (n%d == 0);
			x /= 10;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 12345; int Arg1 = 3; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { int Arg0 = 661232; int Arg1 = 3; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { int Arg0 = 52527; int Arg1 = 0; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { int Arg0 = 730000000; int Arg1 = 0; verify_case(3, Arg1, howMany(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DivisorDigits ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
