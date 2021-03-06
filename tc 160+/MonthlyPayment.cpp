#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MonthlyPayment {
	public:
	long long minimalPayment(string totalSMS, string pack1_, string pay1_, string pack2_, string pay2_) {
		long long pack1, pack2, pay1, pay2, total;
		istringstream(pack1_) >> pack1;
		istringstream(pack2_) >> pack2;
		istringstream(pay1_) >> pay1;
		istringstream(pay2_) >> pay2;
		istringstream(totalSMS) >> total;

		long long sol = total*10;
		for (int i=0; i<2000000; ++i) {
			const long long t = total - i*pack1;
			if (t < 0) break;
			sol = min(sol, i*pay1 + t*10);
			sol = min(sol, i*pay1 + t/pack2*pay2 + t%pack2*10);
			sol = min(sol, i*pay1 + (t+pack2-1)/pack2 * pay2);
		}
		for (int i=0; i<2000000; ++i) {
			const long long t = total - i*pack2;
			if (t < 0) break;
			sol = min(sol, i*pay2 + t*10);
			sol = min(sol, i*pay2 + t/pack1*pay1 + t%pack1*10);
			sol = min(sol, i*pay2 + (t+pack1-1)/pack1 * pay1);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "92"; string Arg1 = "10"; string Arg2 = "90"; string Arg3 = "20"; string Arg4 = "170"; long long Arg5 = 790LL; verify_case(0, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arg0 = "90"; string Arg1 = "10"; string Arg2 = "90"; string Arg3 = "20"; string Arg4 = "170"; long long Arg5 = 770LL; verify_case(1, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arg0 = "99"; string Arg1 = "10"; string Arg2 = "90"; string Arg3 = "20"; string Arg4 = "170"; long long Arg5 = 850LL; verify_case(2, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arg0 = "10"; string Arg1 = "1"; string Arg2 = "11"; string Arg3 = "20"; string Arg4 = "300"; long long Arg5 = 100LL; verify_case(3, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arg0 = "0"; string Arg1 = "10"; string Arg2 = "80"; string Arg3 = "50"; string Arg4 = "400"; long long Arg5 = 0LL; verify_case(4, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { string Arg0 = "28"; string Arg1 = "1"; string Arg2 = "10"; string Arg3 = "1"; string Arg4 = "8"; long long Arg5 = 224LL; verify_case(5, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { string Arg0 = "450702146848"; string Arg1 = "63791"; string Arg2 = "433956"; string Arg3 = "115281"; string Arg4 = "666125"; long long Arg5 = 2604279739220LL; verify_case(6, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_7() { string Arg0 = "45"; string Arg1 = "6"; string Arg2 = "12"; string Arg3 = "7"; string Arg4 = "14"; long long Arg5 = 90LL; verify_case(7, Arg5, minimalPayment(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MonthlyPayment ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
