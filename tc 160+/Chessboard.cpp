#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

class Chessboard {
	public:
	string changeNotation(string cell) {
		if (isdigit(cell[0])) {
			istringstream is(cell);
			int x;
			is >> x;

			string sol(2, ' ');
			sol[0] = (x-1)%8 + 'a';
			sol[1] = (x-1)/8 + '1';

			return sol;
		} else {
			int x = (cell[1]-'1')*8 + cell[0]-'a'+1;
			ostringstream os;
			os << x;
			return os.str();
		}
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1"; string Arg1 = "a1"; verify_case(0, Arg1, changeNotation(Arg0)); }
	void test_case_1() { string Arg0 = "2"; string Arg1 = "b1"; verify_case(1, Arg1, changeNotation(Arg0)); }
	void test_case_2() { string Arg0 = "26"; string Arg1 = "b4"; verify_case(2, Arg1, changeNotation(Arg0)); }
	void test_case_3() { string Arg0 = "c1"; string Arg1 = "3"; verify_case(3, Arg1, changeNotation(Arg0)); }
	void test_case_4() { string Arg0 = "e4"; string Arg1 = "29"; verify_case(4, Arg1, changeNotation(Arg0)); }
	void test_case_5() { string Arg0 = "h8"; string Arg1 = "64"; verify_case(5, Arg1, changeNotation(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Chessboard ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
