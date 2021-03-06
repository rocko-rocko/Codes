
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
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define setbits(x) __builtin_popcount(x) //tell number of 1's in binary form
#define GC getchar_unlocked
//FRACTION
template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};//NOTES:Fraction
template<class T> Fraction<T>::Fraction(T a,T b){T d=GCD(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);}
template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);}
template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);}
//template<class T>inline void output(T a){if(a){T v=a%10;output(a/10);putchar((char)(v+'0'));}}

//template<class T>inline T input(T x){char c=GC();x=0;T s=1;while(c<48||c>57){if(c=='-')s=-1;c=GC();}while(c>=48&&c<=57){x=(x<<3)+(x<<1)+c-48;c=GC();}return x*s;}
template <class T> string str(T Number){

	string Result;          // string which will contain the result

	ostringstream convert;   // stream used for the conversion

	convert << Number;      // insert the textual representation of 'Number' in the characters in the stream

	Result = convert.str();
	return Result;
}
  int StringToNumber ( const string &Text )
  {
     istringstream ss(Text);
     int result;
     return ss >> result ? result : 0;
  }
template<class T> inline vector<pair<T,int> > FACTORISE(T n){vector<pair<T,int> >R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline T TOTIENT(T n) {vector<pair<T,int> > R=FACTORISE(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
double rnd(float d) //for rounding values
{
	          return floor(d + 0.49);
}

int main(){
string test;
while(1){
cin>>test;
if(test=="end")break;
vector<string> a(3);
string faltu="...";
a[0]=faltu;
a[1]=faltu;
a[2]=faltu;
FOR(i,0,sz(test))a[i/3][i%3]=test[i];
int win_x=0;
int win_o=0;
int no_x=0,no_o=0;
getchar();
//FOR(i,0,3)cout<<a[i]<<"\n";cout<<"\n";
for(int i=0;i<3;i++){
int x=0,o=0;
for(int j=0;j<3;j++){
if(a[i][j]=='X'){x++;no_x++;}
if(a[i][j]=='O'){o++;no_o++;}
}
if(x==3){win_x++;}
if(o==3)win_o++;
}
for(int i=0;i<3;i++){
int x=0,o=0;
for(int j=0;j<3;j++){
if(a[j][i]=='X')x++;
if(a[j][i]=='O')o++;
}
if(x==3){win_x++;}
if(o==3){win_o++;}
}
int d_x=0,d_o=0;
int x=0,o=0;
for(int i=0;i<3;i++){
if(a[i][i]=='X')x++;
if(a[i][i]=='O')o++;
}
if(x==3){win_x++;d_x++;}
if(o==3){win_o++;d_o++;}
if(d_x==1 && no_x==no_o+1){printf("valid\n");continue;}
d_x=0;
d_o=0;
x=0;
o=0;
for(int i=0;i<3;i++){
if(a[3-i-1][i]=='X')x++;
if(a[3-i-1][i]=='O')o++;
}
if(x==3){win_x++;d_x++;}
if(o==3){win_o++;d_o++;}
if(d_x==1 && no_x==no_o+1){printf("valid\n");continue;}
if(no_x==0 && no_o==0){printf("invalid\n");continue;}
else{
if(win_x==0 && win_o==0){
if(no_x==no_o+1 && no_x==5)printf("valid\n");
else printf("invalid\n");
continue;
}
else{
if(win_x>0 && win_o>0){printf("invalid\n");continue;}
else{
if(win_x>0){
if(win_x>2){printf("invalid\n");}
else{
if(no_x==no_o+1)printf("valid\n");
else printf("invalid\n");
}
}
else{
if(win_o>1){printf("invalid\n");}
else{
if(no_x==no_o)printf("valid\n");
else printf("invalid\n");
}
}
}
}
}
}
	return 0;
}
