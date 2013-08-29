
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
int start_n,last_n;
int total=0;
int counti=0;
int absurd_n(int n){
int f=0;
while(n){
if(n%10!=0||f==1){
if(f==0){return n;}
}
n/=10;
}
return n;
}
int absurd(int n){
/*string s=str(n);
int abs_n=0;
int i=0;
for(i=sz(s)-1;i>=0;i--)if(s[i]!='0')break;
if(s[i]=='5')abs_n=2*(i+1)-1;
else abs_n=2*(i+1);
return abs_n;*/
int last=0;
int f=0;
while(n){
if(n%10!=0||f==1){
counti++;
if(f==0){last=n%10;f=1;last_n=last;}
}
start_n=n%10;
n/=10;
total++;
}
if(last==5)return 2*counti-1;
return 2*counti;
}
bool check(int abs_n,int low,int high){
if(low>high)return false;
int mid=low+(high-low)/2;
if(absurd(mid)<abs_n)return true;
if(check(abs_n,low,mid-1))return true;
if(check(abs_n,mid+1,high))return true;
return false;
}
int pow(int a,int b){
if(b==0)return 1;
if(b==1)return a;
int ans=pow(a,b/2)*pow(a,b/2);
if(b%2!=0)ans*=a;
return ans;
}
int main(){
int T=SI;
while(T--){
counti=0;
start_n=0;
last_n=0;
total=0;
LL mul=1;
int n=SI;
int a=n*0.95,b=n*1.05;
a=absurd_n(a);
b=absurd_n(b);
if(n==1){printf("not absurd\n");continue;}
int abs_n=absurd(n);
total-=counti;
while(total>0){mul*=10;total--;}
//cout<<n<<" "<<abs_n<<"\n";
string s_n=str(n).substr(0,counti);
if(s_n=="5"){printf("not absurd\n");continue;}
//cout<<s_n<<" "<<counti<<"\n";
string s_a;
if(s_n[sz(s_n)-1]<='5'){
s_a=s_n.substr(0,sz(s_n)-1);
s_a+='0';
}
else{
s_a=s_n.substr(0,sz(s_n)-1);
s_a+='5';
}
if((LL)StringToNumber(s_a)>=a){printf("absurd\n");continue;}
string s_b;
if(s_n[sz(s_n)-1]<'5'){
s_b=s_n.substr(0,sz(s_n)-1);
s_b+='5';
if((LL)(StringToNumber(s_b)+5)<=b){printf("absurd\n");continue;}
}
else{
s_b=s_n.substr(0,sz(s_n)-1);
s_b+='5';
if((LL)(StringToNumber(s_b)+5)<=b && sz(s_n)>1){printf("absurd\n");continue;}
}
printf("not absurd\n");
}
	return 0;
}