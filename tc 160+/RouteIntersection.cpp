#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <map>

using namespace std;

class RouteIntersection {
	public:
	string isValid(int N, vector <int> coords, string moves) {
		map<int, int> p;
        for (int i=0; i<(int)coords.size(); ++i) {
            p[coords[i]] = 0;
        }
        
        set< map<int, int> > S;
        S.insert(p);
        for (int i=0; i<(int)coords.size(); ++i) {
            if (moves[i] == '+') {
                ++p[coords[i]];
            } else {
                --p[coords[i]];
            }
            if (!S.insert(p).second) {
                return "NOT VALID";
            }
        }
        return "VALID";
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "+"; string Arg3 = "VALID"; verify_case(0, Arg3, isValid(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {1,2,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "++--"; string Arg3 = "NOT VALID"; verify_case(1, Arg3, isValid(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {1,2,3,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "+++--"; string Arg3 = "VALID"; verify_case(2, Arg3, isValid(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 344447; int Arr1[] = {132,51717,628,344447,628,51717,344447,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "+-++-+--"; string Arg3 = "NOT VALID"; verify_case(3, Arg3, isValid(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "+-"; string Arg3 = "NOT VALID"; verify_case(4, Arg3, isValid(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 990630; int Arr1[] = {833196,524568,361663,108056,28026,824639,269315,440977,440977,765458,
988451,242440,948414,130873,773990,765458,130873,28026,853121,553636,
581069,82254,735536,833196,898562,898562,940783,988451,540613,317306,
623194,940783,571384,988451,108056,514374,97664}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "--+---+-+++-+-+---++-++-+---+-+--+-++"; string Arg3 = "NOT VALID"; verify_case(5, Arg3, isValid(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RouteIntersection ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
