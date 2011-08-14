#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

double E[1000001];
class TheDiceGame {
	public:
	double expectedThrows(int candies) {
		for (int i=0; i<=candies; ++i) {
			E[i] = 0.0;
		}
		for (int i=1; i<=candies; ++i) {
			for (int j=1; j<=6; ++j) {
				E[i] += ((i-j>=0 ? E[i-j] : 0.0)+1)/6;
			}
		}

		return E[candies];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; double Arg1 = 1.0; verify_case(0, Arg1, expectedThrows(Arg0)); }
	void test_case_1() { int Arg0 = 2; double Arg1 = 1.1666666666666667; verify_case(1, Arg1, expectedThrows(Arg0)); }
	void test_case_2() { int Arg0 = 7; double Arg1 = 2.5216263717421126; verify_case(2, Arg1, expectedThrows(Arg0)); }
	void test_case_3() { int Arg0 = 47; double Arg1 = 13.90476189046144; verify_case(3, Arg1, expectedThrows(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheDiceGame ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
