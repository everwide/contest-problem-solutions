#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class SumAndProduct {
	public:
	int smallestSet(int S, int P) {
		if (S == P) {
            return 1;
        }
        double s = S;
        for (int i=2; i<1000; ++i) {
            double p = 1;
            for (int j=0; j<i; ++j) {
                p *= s/i;
            }
            if (P <= p + 1e-9) {
                return i;
            }
        }
        
        return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 1; verify_case(0, Arg2, smallestSet(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 2; verify_case(1, Arg2, smallestSet(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 100; int Arg2 = -1; verify_case(2, Arg2, smallestSet(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 1000000000; int Arg2 = 9; verify_case(3, Arg2, smallestSet(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SumAndProduct ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
