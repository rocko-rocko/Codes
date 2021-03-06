// BEGIN CUT HERE

// END CUT HERE
#line 5 "PathFinding.cpp"


// AUTHOR: AMAN JAIN
#include <iostream>
#include <sstream>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <deque>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <vector>
#include <queue>

using namespace std;

#define VI vector < int >
#define VVI(A,N,M) vector< VI > A( N, VI (M) )
#define LL long long
#define LLU unsigned long long
#define SI ({int x;scanf("%d",&x);x;})
#define SC ({char x;scanf("%c",&x);x;})
#define PI acos(-1)
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size()) 
#define SORT(c) sort(ALL(c)) 
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define FOR(i,start,end) for(int i=start;i<end;i++)
#define IATOV(a) ({vector<int> v(a,a+sizeof(a)/sizeof(int));v;})
#define CATOV(a) ({vector<char> v(a,a+sizeof(a)/sizeof(char));v;})
#define sieve(a) ({int b=ceil(sqrt(a));VI d(a,0);VI e;int f=2;e.pb(2);e.pb(3);for(int x=1;x<b+1;x++){for(int y=1;y<b+1;y++){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}for(int r=5;r<b+1;r++){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}for(int c=5;c<a;c++){if(d[c]){e.pb(c);}}e;})
#define INF 1000000007
#define EPS 1e-9
#define mt(x, y, z) mp(mp(x,y),z)
template <class T> string str(T Number){

	string Result;          // string which will contain the result

	ostringstream convert;   // stream used for the conversion

	convert << Number;      // insert the textual representation of 'Number' in the characters in the stream

	Result = convert.str();
	return Result;
}
template<class T> inline vector<pair<T,int> > FACTORISE(T n){vector<pair<T,int> >R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline T TOTIENT(T n) {vector<pair<T,int> > R=FACTORISE(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
double rnd(float d) //for rounding values
{
	          return floor(d + 0.49);
}
  typedef struct {
int x1;
int x2;
int y1;
int y2;
int steps;
}node;

 class PathFinding{ 
        public: 
      

int minTurns(vector<string>& board){
node start;
int w=sz(board[0]);
int h=sz(board);
bool visit[20][20][20][20]={{{{false}}}};
FOR(i,0,sz(board))FOR(j,0,sz(board[i])){if(board[i][j]=='A'){start.x1=i;start.y1=j;}if(board[i][j]=='B'){start.x2=i;start.y2=j;}}
start.steps=0;
visit[start.x1][start.y1][start.x2][start.y2]=true;
queue<node> S;
S.push(start);
while(S.empty()==false){
node temp=S.front();
S.pop();
//cout<<temp.x1<<" "<<temp.y1<<" "<<temp.x2<<" "<<temp.y2<<"\n";  
if(
temp.x1==start.x2 &&
temp.x2==start.x1 &&
temp.y1==start.y2 &&
temp.y2==start.y1 )return temp.steps;
for(int i=-1;i<=1;i++){
for(int j=-1;j<=1;j++){
for(int k=-1;k<=1;k++){
for(int l=-1;l<=1;l++){
if(
(temp.x1+i<0 || temp.x1+i>=h) ||
(temp.x2+k<0 || temp.x2+k>=h) ||
(temp.y1+j<0 || temp.y1+j>=w) ||
(temp.y2+l<0 || temp.y2+l>=w) ||
(temp.x1+i==temp.x2 && temp.x2+k==temp.x1 && temp.y1+j==temp.y2 && temp.y2+l==temp.y1)||
(temp.x1+i==temp.x2+k && temp.y2+l==temp.y1+j)
)continue;
if(visit[temp.x1+i][temp.y1+j][temp.x2+k][temp.y2+l]==false && board[temp.x1+i][temp.y1+j]!='X'&& board[temp.x2+k][temp.y2+l]!='X'){
node temp1;
temp1.x1=temp.x1+i;
temp1.y1=temp.y1+j;
temp1.x2=temp.x2+k;
temp1.y2=temp.y2+l;
temp1.steps=temp.steps+1;
visit[temp1.x1][temp1.y1][temp1.x2][temp1.y2]=true;
S.push(temp1);
}
}
}
}
}
}
return -1;
}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"....",
 ".A..",
 "..B.",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minTurns(Arg0)); }
	void test_case_1() { string Arr0[] = {"XXXXXXXXX",
 "A...X...B",
 "XXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, minTurns(Arg0)); }
	void test_case_2() { string Arr0[] = {"XXXXXXXXX",
 "A.......B",
 "XXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, minTurns(Arg0)); }
	void test_case_3() { string Arr0[] = {"XXXXXXXXX",
 "A.......B",
 "XXXX.XXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, minTurns(Arg0)); }
	void test_case_4() { string Arr0[] = {"...A.XXXXX.....",
 ".....XXXXX.....",
 "...............",
 ".....XXXXX.B...",
 ".....XXXXX....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(4, Arg1, minTurns(Arg0)); }
	void test_case_5() { string Arr0[] = {"AB.................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "X..................X",
 ".XXXXXXXXXXXXXXXXXXX",
 "X..................X",
 "XXXXXXXXXXXXXXXXXXX.",
 "...................X",
 ".XXXXXXXXXXXXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 379; verify_case(5, Arg1, minTurns(Arg0)); }

// END CUT HERE
 
 }; 

    // BEGIN CUT HERE 
 int main(){
        PathFinding ___test; 
        ___test.run_test(-1); 
 } 
    // END CUT HERE
