#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Homomorphism {
	public:
	int count(string u, string v) {
		if (u.find('0')==string::npos || u.find('1')==string::npos)
			return v.size()%u.size()==0 ? -1 : 0;

		int sol = 0;
		int first = 0;
		while (u[first] == u[0])
			++first;
		for (int i=1; i*first<(int)v.size(); ++i) {
			const string &h = v.substr(0, i);
			string cur;

			for (int j=0; j<first; ++j)
				cur += h;

			for (int j=1; cur.size()+j<=v.size(); ++j) {
				const string &hh = v.substr(cur.size(), j);
				string x;
				for (int k=0; k<(int)u.size(); ++k)
					x += (u[k]==u[0] ? h : hh);
				sol += (x==v);
			}
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "10"; string Arg1 = "11001"; int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "00"; string Arg1 = "11111"; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "11"; string Arg1 = "00"; int Arg2 = -1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "001"; string Arg1 = "1010001"; int Arg2 = 1; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "101"; string Arg1 = "11111111111111111111111111111111111111111111111111"; int Arg2 = 24; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Homomorphism ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
