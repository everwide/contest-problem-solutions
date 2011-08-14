#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool beats(int a, int b) {
	if (a>=90 && b<=90)
		return false;
	else if (a>=90 && b>90)
		return b > a;
	else if (a<90 && b<=90)
		return false;
	else
		return a >= 180-b;
}
bool loses(int a, int b) {
	if (a>=90 && b<=90)
		return false;
	else if (a>=90 && b>90)
		return false;
	else if (a<90 && b<=90)
		return a < b;
	else
		return a < 180-b;
}
class Crossroads {
	public:
	vector <int> getOut(vector <int> angles) {
		vector<int> cars;
		for (int i=0; i<(int)angles.size(); ++i)
			cars.push_back(i);

		int cnt = 51;
		while (cnt--)
		for (int i=0; i<(int)cars.size()-1; ++i)
			if (beats(angles[cars[i]], angles[cars[i+1]])) {
				cars.erase(cars.begin()+i+1);
			} else if (loses(angles[cars[i]], angles[cars[i+1]])) {
				cars.erase(cars.begin()+i);
				--i;
			}

		return cars;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {105, 75, 25, 120, 35, 75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  1,  5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getOut(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  1,  2,  3,  4,  5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getOut(Arg0)); }
	void test_case_2() { int Arr0[] = {13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getOut(Arg0)); }
	void test_case_3() { int Arr0[] = {90, 123, 1, 23, 132, 11, 28, 179, 179, 77, 113, 91}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getOut(Arg0)); }
	void test_case_4() { int Arr0[] = {179, 89, 90, 91, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  2,  4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getOut(Arg0)); }
	void test_case_5() { int Arr0[] = {89, 91}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getOut(Arg0)); }
	void test_case_6() { int Arr0[] = {140, 118, 54, 166, 151, 44, 90, 5, 14, 6,
 64, 129, 74, 33, 134, 25, 11, 95, 65, 145,
 29, 162, 24, 147, 45, 103, 63, 97, 120, 156,
 167, 170, 19, 28, 100, 144, 161, 13, 157, 148}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  1,  6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, getOut(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Crossroads ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
