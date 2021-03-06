#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define ii pair<int, int>
#define mp make_pair
#define mt make_tuple
#define DESYNC                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define pb push_back
#define vi vector<int>
#define vii vector<ii>
#define all(x) x.begin(), x.end()
#define EPS 1e-9
#define INF 1e18
#define ROOT 1
#define M 1000000007
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

void solution() {
  int k, m;
  cin >> k >> m;
  int n = ((1LL << m) - k - 1) / 2 + 1;
  vector<string> v(k);
  for (int i = 0; i < k; i++) cin >> v[i];
  string ans = "";
  for (int i = 0; i < m; i++) {
    // zero
    int cnt = (1LL << (m - 1 - i));
    for (string s : v)
      if (s[i] == '0') cnt--;
    if (cnt >= n) {
      ans += '0';
      vector<string> new_v;
      for (string s : v)
        if (s[i] == '0') new_v.pb(s);
      v.swap(new_v);
    } else {
      // one
      ans += '1';
      vector<string> new_v;
      for (string s : v)
        if (s[i] == '1') new_v.pb(s);
      v.swap(new_v);
      n -= cnt;
    }
  }
  cout << ans << endl;
}

int32_t main() {
  DESYNC;
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
}

