#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<double> calc(int n, int sz, const vector<int> &a, const vector<int> &b) {
    vector<double> ret(sz+1, 0.0);
    for (int i=0; i<n; ++i) {
        for (int j=a[i]; j<=b[i]; ++j) {
            ret[j] += 1.0/(b[i]-a[i]+1)/n;
        }
    }
    
    return ret;
}
class TheFansAndMeetingsDivTwo {
	public:
	double find(vector <int> minJ, vector <int> maxJ, vector <int> minB, vector <int> maxB) {
		int n = minJ.size();
        int t = max(*max_element(maxJ.begin(), maxJ.end()), *max_element(maxB.begin(), maxB.end()));
        vector<double> A = calc(n, t, minJ, maxJ);
        vector<double> B = calc(n, t, minB, maxB);
        
        double sol = 0.0;
        for (int i=0; i<=t; ++i) {
            sol += A[i]*B[i];
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.3333333333333333; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {5, 7, 7, 1, 6, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 9, 7, 3, 9, 5, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9, 12, 10, 14, 50, 9, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {9, 13, 50, 15, 50, 12, 11}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.014880952380952378; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {44}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {47}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.0; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1, 6, 3, 1, 4, 3, 5, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 8, 5, 7, 9, 7, 9, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 1, 5, 3, 1, 2, 4, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {9, 2, 7, 9, 4, 5, 4, 9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 0.11562305130385474; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheFansAndMeetingsDivTwo ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
