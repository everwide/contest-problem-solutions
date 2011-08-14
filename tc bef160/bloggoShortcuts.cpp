#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef long long i64;

class bloggoShortcuts {
  public:
  string expand(string text) {
    
    int i;
    while ((i=text.find('_')) != string::npos) {
    	text.erase(i,1);
    	text.insert(i, "<i>");
    	i = text.find('_');
    	assert(i != string::npos);
    	text.erase(i,1);
    	text.insert(i, "</i>");
    }
    while ((i=text.find('*')) != string::npos) {
    	text.erase(i,1);
    	text.insert(i, "<b>");
    	i = text.find('*');
    	assert(i != string::npos);
    	text.erase(i,1);
    	text.insert(i, "</b>");
    }
    return text;
  }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "You _should_ see the new walrus at the zoo!"; string Arg1 = "You <i>should</i> see the new walrus at the zoo!"; verify_case(0, Arg1, expand(Arg0)); }
	void test_case_1() { string Arg0 = "Move it from *Accounts Payable* to *Receiving*."; string Arg1 = "Move it from <b>Accounts Payable</b> to <b>Receiving</b>."; verify_case(1, Arg1, expand(Arg0)); }
	void test_case_2() { string Arg0 = "I saw _Chelydra serpentina_ in *Centennial Park*."; string Arg1 = "I saw <i>Chelydra serpentina</i> in <b>Centennial Park</b>."; verify_case(2, Arg1, expand(Arg0)); }
	void test_case_3() { string Arg0 = " _ _ __  _ yabba dabba _   *  dooooo  * ****"; string Arg1 = " <i> </i> <i></i>  <i> yabba dabba </i>   <b>  dooooo  </b> <b></b><b></b>"; verify_case(3, Arg1, expand(Arg0)); }
	void test_case_4() { string Arg0 = "_now_I_know_*my*_ABC_next_time_*sing*it_with_me"; string Arg1 = "<i>now</i>I<i>know</i><b>my</b><i>ABC</i>next<i>time</i><b>sing</b>it<i>with</i>me"; verify_case(4, Arg1, expand(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    bloggoShortcuts ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
