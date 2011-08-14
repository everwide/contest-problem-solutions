#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v;
bool test(int x) {
	string s(v.size(), 0);

	for (int i=0; i<(int)v.size(); ++i)
		if (v[i] >= x)
			s[i] = 'H';
		else
			s[i] = 'L';

	return 2*count(s.begin(), s.end(), 'L')>(int)s.size() && s.find("LHHL")==string::npos;
}
class ClapLight {
	public:
	int threshold(vector <int> background) {
		v = background;

		for (int sol=0; sol<=1001; ++sol)
			if (test(sol))
				return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,6,6,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(0, Arg1, threshold(Arg0)); }
	void test_case_1() { int Arr0[] = { 5,8,7,6,12,8,4,3,2,6 } ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(1, Arg1, threshold(Arg0)); }
	void test_case_2() { int Arr0[] = {8,8,8,1,1,1,1,1,1,1,1,1,1,1,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, threshold(Arg0)); }
	void test_case_3() { int Arr0[] = {921,1,5,900,8,813,3,3,3,3,3,3,3,813,813}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, threshold(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ClapLight ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
