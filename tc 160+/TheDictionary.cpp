#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long C[201][201];
long long lim = 123456789012LL;
class TheDictionary {
	public:
	string find(int n, int m, int k) {
		C[0][0] = 1;
        for (int n=1; n<201; ++n) {
            C[n][0] = 1;
            for (int k=1; k<=n; ++k) {
                C[n][k] = min(lim, C[n-1][k-1] + C[n-1][k]);
            }
        }
        
        if (C[m+n][m] < k) {
            return "";
        }
        
        string sol;
        while (m+n > 0) {
            if (n>0 && k<=C[m+n-1][n-1]) {
                sol += 'a';
                --n;
            } else {
                sol += 'z';
                k -= C[m+n-1][m];
                --m;
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; string Arg3 = "azaz"; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 6; string Arg3 = "zzaa"; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 1000000000; string Arg3 = ""; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 47; string Arg3 = "aaazazaazaz"; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheDictionary ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
