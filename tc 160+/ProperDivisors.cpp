#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class ProperDivisors {
	public:
	int analyzeInterval(int a, int b, int n) {
        b += a;
        long long sol = 0;

        for (long long x=2; x<=b; ++x) {
            long long hi = b / x;
            long long lo = (a-1) / x;
            lo = max(lo, 1LL);
            if (lo >= hi) {
                continue;
            }
            sol += hi - lo;

            long long y = 1;
            for (int i=0; i<n; ++i) {
                y *= x;
                if (y > b) {
                    break;
                }
            }
            hi = b / y;
            lo = (a-1) / y;
            if (lo >= hi) {
                continue;
            }
            sol -= hi - lo;
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 32; int Arg1 = 1; int Arg2 = 3; int Arg3 = 5; verify_case(0, Arg3, analyzeInterval(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 12; int Arg2 = 2; int Arg3 = 8; verify_case(1, Arg3, analyzeInterval(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000000; int Arg1 = 10000000; int Arg2 = 10; int Arg3 = 146066338; verify_case(2, Arg3, analyzeInterval(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ProperDivisors ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
