#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class SoldierLabeling {
	public:
	int count(int n, int lowerBound, int upperBound) {
		int lower = 1, upper = 1;
        for (int i=0; i<lowerBound; ++i) {
            lower *= 10;
        }
        lower /= 10;
        for (int i=0; i<upperBound; ++i) {
            upper *= 10;
        }
        int up = min(n+1, upper);
        return max(0, up - lower);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 2; int Arg2 = 2; int Arg3 = 90; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 31; int Arg1 = 2; int Arg2 = 3; int Arg3 = 22; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 8; int Arg3 = 0; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10000000; int Arg1 = 8; int Arg2 = 8; int Arg3 = 1; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2718317; int Arg1 = 3; int Arg2 = 7; int Arg3 = 2718218; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SoldierLabeling ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
