#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

class ChangingString {
	public:
	int distance(string A, string B, int K) {
		vector<int> dist;

		for (int i=0; i<(int)A.size(); ++i)
			dist.push_back(abs(A[i]-B[i]));

		sort(dist.begin(), dist.end());

		for (int i=(int)dist.size()-1; i>=((int)dist.size()-K); --i)
			dist[i] = (dist[i] ? 0 : 1);

		return accumulate(dist.begin(), dist.end(), 0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ab"; string Arg1 = "ba"; int Arg2 = 2; int Arg3 = 0; verify_case(0, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "aa"; string Arg1 = "aa"; int Arg2 = 2; int Arg3 = 2; verify_case(1, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "aaa"; string Arg1 = "baz"; int Arg2 = 1; int Arg3 = 1; verify_case(2, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "fdfdfdfdfdsfabasd"; string Arg1 = "jhlakfjdklsakdjfk"; int Arg2 = 8; int Arg3 = 24; verify_case(3, Arg3, distance(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "aa"; string Arg1 = "bb"; int Arg2 = 2; int Arg3 = 0; verify_case(4, Arg3, distance(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ChangingString ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
