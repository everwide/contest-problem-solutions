#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class InfiniteAddition {
	public:
	string giveExample(int sum, int op1, int op2) {
		
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 3; string Arg3 = "(AAABZB)=(AB)+(ZYZ)"; verify_case(0, Arg3, giveExample(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 5; string Arg3 = "NO SOLUTION"; verify_case(1, Arg3, giveExample(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 5; string Arg3 = "(AAAAB)=(AAAAC)+(ZZZZY)"; verify_case(2, Arg3, giveExample(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 5; string Arg3 = "(A)=(AAAAB)+(ZZZZY)"; verify_case(3, Arg3, giveExample(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    InfiniteAddition ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
