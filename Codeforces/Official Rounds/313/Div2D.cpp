#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define DESYNC ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector< ii >
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);
 
using namespace std;
 
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
 
int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}
 
string calc(string a){
  if(a.size()%2) return a;
  string a1 = calc(a.substr(0, a.size()/2));
  string a2 = calc(a.substr(a.size()/2, a.size()/2));
  if(a1 < a2) return a1 + a2;
  else return a2 + a1;
}
 
int32_t main(){
  DESYNC;
  string a,b;
  cin >> a >> b;
  a = calc(a);
  b = calc(b);
  if(a == b) cout << "YES" << endl;
  else cout << "NO" << endl;
}
 
