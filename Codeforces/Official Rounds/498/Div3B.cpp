#include <bits/stdc++.h>
 
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
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
  if(a == 0) return b;
  else return gcd(b%a, a);
}
 
int32_t main(){
  DESYNC;
  int n, k;
  cin >> n >> k;
  ii v[n];
  for(int i=0; i<n; i++){
  	cin >> v[i].ff;
  	v[i].ss = (i+1);
  }
  sort(v, v+n, greater< ii >());
  int sum = 0;
  vector<int> ans;
  for(int i=0; i<k; i++){
  	sum += v[i].ff;
  	ans.pb(v[i].ss);
  }
  cout << sum << endl;
  sort(ans.begin(), ans.end());
  int ini = 1;
  for(int i=0; i<ans.size()-1; i++){
  	int x = ans[i];
  	cout << (x - ini + 1) << " ";
  	ini = x+1;
  }
  cout << n - ini + 1 << endl;
}
 
