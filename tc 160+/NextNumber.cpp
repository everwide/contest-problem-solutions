#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class NextNumber {
	public:
	int getNextNumber(int N) {
		vector<int> t;
        while (N > 0) {
            t.push_back(N&1);
            N >>= 1;
        }
        t.push_back(0);

        reverse(t.begin(), t.end());
        next_permutation(t.begin(), t.end());
        for (int i=0; i<(int)t.size(); ++i) {
            N = (N<<1) | t[i];
        }

        return N;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1717; int Arg1 = 1718; verify_case(0, Arg1, getNextNumber(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 8; verify_case(1, Arg1, getNextNumber(Arg0)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 11; verify_case(2, Arg1, getNextNumber(Arg0)); }
	void test_case_3() { int Arg0 = 12; int Arg1 = 17; verify_case(3, Arg1, getNextNumber(Arg0)); }
	void test_case_4() { int Arg0 = 555555; int Arg1 = 555557; verify_case(4, Arg1, getNextNumber(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NextNumber ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
