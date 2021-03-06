#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int need(const vector<int> &v, int d) {
	int ret = 0;

	int where = 0;
	for (int i=0; i<(int)v.size(); ++i) {
		while (v[i]-where > d) {
			++ret;
			where += d;
		}
		where = max(where, v[i]);
	}

	return ret;
}
class Turnpike {
	public:
	int unserviced(int len, int n, vector <int> plazas) {
		plazas.push_back(0);
		plazas.push_back(len);

		sort(plazas.begin(), plazas.end());

		int lo = 1;
		int hi = len;

		while (lo < hi) {
			int mid = lo + (hi-lo)/2;
			if (need(plazas, mid) <= n)
				hi = mid;
			else
				lo = mid+1;
		}

		return lo;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1000; int Arg1 = 1; int Arr2[] = {300,701,800}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 300; verify_case(0, Arg3, unserviced(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1000; int Arg1 = 1; int Arr2[] = {200,701,800}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 251; verify_case(1, Arg3, unserviced(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 800; int Arg1 = 7; int Arr2[] = {622,411,201,555,755,82}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 70; verify_case(2, Arg3, unserviced(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Turnpike ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
