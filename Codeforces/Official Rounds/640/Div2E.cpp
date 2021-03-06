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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<bool> bsht(n + 1, false);
    for (int i = 0; i < n; i++) {
      int acc = 0;
      for (int j = i; j < n; j++) {
        acc += v[j];
        if (acc > n) break;
        if (j != i) bsht[acc] = true;
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
      if (bsht[v[i]]) cnt++;
    cout << cnt << endl;
  }
}

int32_t main() {
  DESYNC;
  solution();
}

