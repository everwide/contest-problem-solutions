#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

/*
great use of union find (in the comment)
*/
class RightTriangle {
	public:
	long long triangleCount(int places, int points, int a, int b, int c) {
        if (places & 1) {
            return 0;
        }
		set<long long> S;
        for (int i=0; i<places; ++i) {
            S.insert(i);
        }
        vector<long long> V;
        for (long long n=0; n<points; ++n) {
            long long p = (n*n*a + n*b + c) % places;
            set<long long>::iterator it = S.lower_bound(p);
            if (it == S.end()) {
                it = S.begin();
            }
            V.push_back(*it);
            S.erase(it);
        }
        
        /* alternatively, instead of using a set of unused places an lower_bound,
         * we could use union find such that the get_root(x) returns the place 
         * that is to be chosen for this point if x is generated by the p-formula...
         *
         * int parent[1000001];
         * int get_root(x) {
         *   return parent[x]==-1 ? x : (parent[x] = get_root(x)); // path halving
         * }
         *
         * ...
         * memset(parent, 0xff, sizeof parent);
         * for (long long n=0; n<points; ++n) {
         *  long long p = (n*n*a + n*b + c) % places;
         *  int pp = get_root(p);
         *  used[pp] = true;
         *  parent[pp] = (pp+1)%places; // since pp is taken, next time take 
         *  // the root of (pp+1)%places (might be (pp+1)%places itself if it is
         *  // not used already
         */
        
        sort(V.begin(), V.end());
        long long sol = 0;
        for (long long i=0; i<(long long)V.size(); ++i) {
            long long p = V[i];
            long long p2 = (p + places/2) % places;
            long long j = lower_bound(V.begin(), V.end(), p2) - V.begin();
            if (j==V.size() || V[j]!=p2) {
                continue;
            }
            if (j < i) {
                j += V.size();
            }
            sol += (j-i-1); // this j-i-1 will always be the same and equal (points-2)/2
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 3; int Arg2 = 0; int Arg3 = 3; int Arg4 = 0; long long Arg5 = 0LL; verify_case(0, Arg5, triangleCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 40; int Arg1 = 3; int Arg2 = 5; int Arg3 = 0; int Arg4 = 0; long long Arg5 = 1LL; verify_case(1, Arg5, triangleCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 16; int Arg3 = 24; int Arg4 = 17; long long Arg5 = 4LL; verify_case(2, Arg5, triangleCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 47000; int Arg2 = 0; int Arg3 = 2; int Arg4 = 5; long long Arg5 = 0LL; verify_case(3, Arg5, triangleCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 200000; int Arg1 = 700; int Arg2 = 123456; int Arg3 = 789012; int Arg4 = 345678; long long Arg5 = 6980LL; verify_case(4, Arg5, triangleCount(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RightTriangle ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE
