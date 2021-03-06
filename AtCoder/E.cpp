#include <bits/stdc++.h>

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
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
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

vector<set<ii, greater<ii>>> kinders(212345);
set<ii> ans;
void solution() {
  int n, q;
  cin >> n >> q;
  int child[n + 1];
  int kinder[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> child[i] >> kinder[i];
    if (kinders[kinder[i]].size() > 0)
      ans.erase(ii(kinders[kinder[i]].begin()->ff, kinder[i]));
    kinders[kinder[i]].insert(ii(child[i], i));
    ans.insert(ii(kinders[kinder[i]].begin()->ff, kinder[i]));
  }
  while (q--) {
    int c, d;
    cin >> c >> d;
    ans.erase(ii(kinders[kinder[c]].begin()->ff, kinder[c]));
    kinders[kinder[c]].erase(ii(child[c], c));
    if (kinders[kinder[c]].size() > 0) {
      ans.insert(ii(kinders[kinder[c]].begin()->ff, kinder[c]));
    }
    kinder[c] = d;
    if (kinders[kinder[c]].size() > 0) {
      ans.erase(ii(kinders[kinder[c]].begin()->ff, kinder[c]));
    }
    kinders[kinder[c]].insert(ii(child[c], c));
    ans.insert(ii(kinders[kinder[c]].begin()->ff, kinder[c]));
    // for (ii x : kinders[2]) cout << "-> " << x.ff << " " << x.ss << endl;
    // for (ii x : ans) cout << x.ff << " " << x.ss << endl;
    cout << ans.begin()->ff << endl;
  }
}

int32_t main() {
  DESYNC;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t = 1;
#ifdef MULTIPLE_TEST_CASE
  cin >> t;
#endif
  while (t--) solution();
}

