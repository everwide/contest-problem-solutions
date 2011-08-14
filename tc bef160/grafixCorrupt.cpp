#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class grafixCorrupt {
   public:
   int max, sol;
   
   int selectWord(vector <string> dictionary, string candidate) {
     max = 0;
   	 for (int i=0; i<dictionary.size(); ++i) {
   		 int count = 0;
   		 int lim = min(dictionary[i].size(), candidate.size());
   		 for (int j=0; j<lim; ++j)
   		   count += (dictionary[i][j]==candidate[j]);
   		 if (count > max) {
   		    max = count;
   		    sol = i;
   		 }
   	 }         
   	return (max) ? sol : -1;    
   }







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"cat", "cab", "lab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "dab"; int Arg2 = 1; verify_case(0, Arg2, selectWord(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"cat", "cab", "lab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "lag"; int Arg2 = 2; verify_case(1, Arg2, selectWord(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"cat", "cab", "lab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "bic"; int Arg2 = -1; verify_case(2, Arg2, selectWord(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"zkv", "izs", "fed", "waa", "ttx", "bgt", "quy", "dtq", "dgo", "yrs",
 "cid", "nln", "pvz", "txt", "zun", "erd", "jen", "klh", "kxy", "emf",
 "mqt", "lza", "dzb", "ndx", "vfr", "jhs", "dkm", "elb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "cwd"; int Arg2 = 10; verify_case(3, Arg2, selectWord(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"zhadjsg", "vzptftx", "fbaslxs", "ejejncm", "xpxkeae", "ixrrtzw",
 "ovctbzx", "sfzekhh", "lxzixjk", "jixdpik", "bkianck", "laclyin",
 "uqmdkfx", "dimswqo", "fojhetr", "grntrce", "obdtqwx", "bhojwcy",
 "zuuuvst", "mvqtoly", "aftmupx", "govuidx", "qklpret", "yptccki",
 "uxdnslh", "wudrusz", "uwxbvou", "ouytqun", "pjdexqe", "xraaqdw",
 "lxmoncl", "sjnjfgb", "qrlqgvc", "fgvoadm", "yohsrxw", "udpvrsr",
 "mklucgt"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "vklikgf"; int Arg2 = 36; verify_case(4, Arg2, selectWord(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    grafixCorrupt ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
