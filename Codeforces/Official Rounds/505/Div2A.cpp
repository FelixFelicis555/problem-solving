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
const double PI = acos(-1);

using namespace std;

inline int mod(int n){ return (n%1000000007); }

int gcd(int a, int b){
  if(a == 0 || b == 0) return 0;
  else return abs(__gcd(a,b));
}

int32_t main(){
  DESYNC;
  int n;
  cin >> n;
  if(n == 1){
    cout << "Yes" << endl;
    return 0;
  }
  string s;
  cin >> s;
  int cnt[26];
  for(int i=0; i<26; i++) cnt[i] = 0;
  for(char c : s) cnt[c-'a']++;
  bool ok = false;
  for(int i=0; i<26; i++) if(cnt[i] >= 2) ok = true;
  cout << (ok ? "Yes" : "No") << endl;
}

