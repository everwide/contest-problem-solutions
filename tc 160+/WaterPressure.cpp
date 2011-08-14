#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <cctype>

using namespace std;

const int di[] = { -1,  0,  1,  0 };
const int dj[] = {  0,  1,  0, -1 };

int m, n;

bool valid(int i, int j) {
	return i>=0 && i<m && j>=0 && j<n;
}
class WaterPressure {
	public:
	int howLong(vector <string> layout) {
		m = layout.size();
		n = layout[0].size();

		int total = 1;
		int flooded = 1;
		int time = 0;
		int unflood = 0;
		int mininc = 1;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (isdigit(layout[i][j]))
					++unflood;

		for (;;) {
			total += mininc;
			bool flag = false;
			for (int i=0; i<m; ++i)
				for (int j=0; j<n; ++j)
					if (layout[i][j]=='.')
						for (int dir=0; dir<4; ++dir) {
							const int ii = i+di[dir];
							const int jj = j+dj[dir];
							if (valid(ii, jj) && isdigit(layout[ii][jj])) {
								flag = true;
								goto kraj;
							}
						}
kraj:	if (!flag)
				return -1;

			mininc = 100000;
			set<pair<int, int> > update;
			for (int i=0; i<m; ++i)
				for (int j=0; j<n; ++j)
					if (layout[i][j] == '.')
						for (int dir=0; dir<4; ++dir) {
							const int ii = i+di[dir];
							const int jj = j+dj[dir];
							if (valid(ii, jj) && isdigit(layout[ii][jj]))
								if (total > flooded*(layout[ii][jj]-'0')) {
									update.insert(make_pair(ii, jj));
									mininc = 1;
								} else {
									mininc = min(mininc, max(1, flooded*(layout[ii][jj]-'0') - total));
								}
						}
			flooded += update.size();
			unflood -= update.size();
			if (unflood == 0)
				return time;
			for (set<pair<int, int> >::const_iterator it=update.begin(); it!=update.end(); ++it)
				layout[it->first][it->second] = '.';

			time += mininc;
		}
		return -2;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
".0",
"0X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, howLong(Arg0)); }
	void test_case_1() { string Arr0[] = {
".0",
"00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, howLong(Arg0)); }
	void test_case_2() { string Arr0[] = {
".5",
"44"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(2, Arg1, howLong(Arg0)); }
	void test_case_3() { string Arr0[] = {".23456789"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 71; verify_case(3, Arg1, howLong(Arg0)); }
	void test_case_4() { string Arr0[] = {
".X0",
"X00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, howLong(Arg0)); }
	void test_case_5() { string Arr0[] = {
".85773817518159249980260123498780838839X6384717463",
"242194445126058X5X93973323184X3X2747X842171X286218",
"598X67822897X5X61920060240170X31256497102692827551",
"54X36408X2548801X136636X63X9233X5949346X2274580162",
"5108021354X77X4477509918743895XXX159760734682X9115",
"50675439X0922X79916947371X01901217614357X0397201X3",
"27186118593416001273104X29X76977141883369859598888",
"80914X110594111X436841522027X668157791200228638293",
"940105447111X78X25011577574123524X04XXX51614492051",
"8804363635177X8246382862576X601870X74X139993345821",
"X48877009143171494700XX3X16138573259477742520850X9",
"1612588394913980186365912312794180464979928X986475",
"595353627322252222412X883094875X522435782213598237",
"17391130462739808923430X258255508957X4539278411137",
"161196X087X1959308152303433460329X6588920868810551",
"5X05897317154867X286045721X246725361349XX31742455X",
"X6356984801056259X735653998127X568670314628X485224",
"9320088X74859675156365X779X1X326767X79844419358X2X",
"501055497X39933X951356690965X4X0844917186293X57985",
"33413302X1903266448066612423X8038586XX5638903X7517",
"2976X251488X07X87464805678010167X32X54795816434863",
"18X8XX869283086X940798825X85739462998X3X3834428505",
"2555044879X7309586526260751345349591446476X7010X13",
"3233684019X20X770513442033X6950060849326X814045XX1",
"7378853595549545X9334157X55988471X21X3295375894550",
"7X9037779323X31807337002826035684828290777975X01X4",
"88X7X979X7X39506209854X7415XX8999X2253016X25035787",
"7683015X17268X16694392X6X101441658747937X198485622",
"1624X697868860600X030X577356X121482831384673XX7334",
"4662712538X13X4168850436576272047034855X5933218977",
"363X88X712383950892X775895613479X5287X01182X614158",
"0944515500373672425X6066X2108X3247524582717066X178",
"637664873632165059897471275828595X6527260271X84X40",
"305512X0X86260235207058X57705027964497905850617962",
"935138076111582XX0369X62229X178X921961753325422758",
"9987594X029815548549X858304X3181752985X5927X716348",
"631347X74X23510X703201850X965X8803X5794257X7X32012",
"597X2244071123X41X44196191328874040522673675346X00",
"9501X65935X9375252X55199X261467XXX8118871789524X62",
"732087503876417410X23X95740041509X58104X7543083124",
"175978X56605686460653815X08585X89XX137855313405573",
"51593131735080324921X2253417397314274XX231X5293926",
"XX778362173333574X333953005142250501X79X21757X1264",
"57350X7252505123850942501148X63526X106805090642546",
"2331X884X085X068X18X612328531670865X09525594XX98X6",
"6935X60327121102150643X49857600X77316813X362130791",
"331X29776535751774789772426596X1961969905180339X10",
"358X6622772195016X79558982X1024678439091439835013X",
"305362575995391477X2744272460098891730534152558XX1",
"28318306546365480X775289935065X4X48610794894231736"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18566; verify_case(5, Arg1, howLong(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WaterPressure ___test;
    ___test.run_test(-1);
    }
// END CUT HERE
