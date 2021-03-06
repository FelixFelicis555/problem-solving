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
#define curtime chrono::steady_clock::now().time_since_epoch().count
#define rep(i, beg, n, s) for (int i = beg; i < n; i += s)
const double PI = acos(-1);

using namespace std;

inline int mod(int n, int m = M) {
  int ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}

int exp(int n, int k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  int ax = exp(n, k / 2);
  ax = mod(ax * ax);
  if (k % 2) ax = mod(ax * n);
  return ax;
}

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
//#define MULTIPLE_TEST_CASE

void solution() {
  int n;
  cin >> n;
  int v[n];
  map<ii, int> real_sz;
  set<tuple<int, int, int>> s;
  set<tuple<int, int, int>> cur;

  vector<ii> ax;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (ax.size() == 0)
      ax.pb(ii(i, x));
    else {
      if (ax.back().ss == x)
        ax.pb(ii(i, x));
      else {
        cur.insert(mt(ax.front().ff, ax.back().ff, ax.back().ss));
        ax.clear();
        ax.pb(ii(i, x));
      }
    }
  }
  if (ax.size() > 0) {
    cur.insert(mt(ax.front().ff, ax.back().ff, ax.back().ss));
    ax.clear();
  }
  for (auto k : cur) {
    int st, ed, x;
    tie(st, ed, x) = k;
    real_sz[ii(st, ed)] = ed - st + 1;
    s.insert(mt(-real_sz[ii(st, ed)], st, ed));
  }

  int ans = 0;
  while (s.size() > 0) {
    int st, ed, sz;
    tie(sz, st, ed) = *s.begin();
    s.erase(s.begin());
    ans++;
    auto it = cur.lower_bound(mt(st, ed, -1));
    // cout << "removing " << st << " " << ed << endl;
    int lst, led, lx;
    if (it != cur.begin()) {
      it--;
      tie(lst, led, lx) = *it;
      it++;
    } else {
      cur.erase(it);
      continue;
    }
    it++;
    int rst, red, rx;
    if (it != cur.end()) {
      tie(rst, red, rx) = *it;
      it--;
    } else {
      it--;
      cur.erase(it);
      continue;
    }

    if (lx == rx) {
      cur.erase(mt(rst, red, rx));
      cur.erase(mt(lst, led, lx));
      s.erase(mt(-real_sz[ii(rst, red)], rst, red));
      s.erase(mt(-real_sz[ii(lst, led)], lst, led));
      cur.insert(mt(lst, red, lx));
      real_sz[ii(lst, red)] = real_sz[ii(rst, red)] + real_sz[ii(lst, led)];
      s.insert(mt(-real_sz[ii(lst, red)], lst, red));
    }

    cur.erase(it);
  }
  cout << ans << endl;
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

