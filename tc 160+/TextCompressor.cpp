#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TextCompressor {
	public:
	string longestRepeat(string sourceText) {
		for (int len=(int)sourceText.size()/2; len>0; --len)
			for (int i=0; i+2*len<=(int)sourceText.size(); ++i)
				if (sourceText.substr(i+len).find(sourceText.substr(i, len)) != string::npos)
					return sourceText.substr(i, len);
		return "";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCDABCFG"; string Arg1 = "ABC"; verify_case(0, Arg1, longestRepeat(Arg0)); }
	void test_case_1() { string Arg0 = "ABABA"; string Arg1 = "AB"; verify_case(1, Arg1, longestRepeat(Arg0)); }
	void test_case_2() { string Arg0 = "This is a test."; string Arg1 = "is "; verify_case(2, Arg1, longestRepeat(Arg0)); }
	void test_case_3() { string Arg0 = "Testing testing 1 2 3."; string Arg1 = "esting "; verify_case(3, Arg1, longestRepeat(Arg0)); }
	void test_case_4() { string Arg0 = "The quick brown fox jumps over the lazy dog."; string Arg1 = "he "; verify_case(4, Arg1, longestRepeat(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TextCompressor ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
