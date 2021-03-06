#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define endl '\n'
#define pb push_back
#define ii pair<int,int>
#define vii vector< ii >
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ff first
#define ss second
#define int long long
#define double float

using namespace std;
using namespace __gnu_pbds;

inline int mod(int n){ return (n%1000000007); } 

//////////////////////////////////////////////STL - Ordered Set////////////////////////////////////////////
typedef tree<
int, //change for pair<int,int> to use like multiset
null_type,
less<int>, //change for pair<int,int> to use like multiset
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int differ = 0;
//////////////////////////////////////////////EXTRAS///////////////////////////////////////////////////////

int get(double want, int sum){
	int l = 0, r = ((int)1e18+(sum-1))/sum;
	int ans = 0;
	for(int i=0; i<200; i++){
		int m = (l+r)/2;
		double val = sum*m;
		if(val <= want){
			ans = m;
			l = m+1;
		}
		else r = m-1;
	}
	return ans;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int k,d,t;
	cin >> k >> d >> t;
	if(k%d == 0){
		cout << t << endl;
		return 0;
	}
	int ot = t;
	d = ((k+(d-1))/d)*d - k;
	int cyc = (2*t)/(2*k+d);
	int ans = cyc*(2*k+2*d);
	t+= t;
	t -= cyc*(2*k+d);
	//cout << cyc << " " << t << endl;
	//cout << ans << endl;
	if(t <= 2*k) ans += t;
	else {
		ans += 2*k;
		t -= 2*k;
		ans += 2*t;
	}
	//cout << ans << endl;
	if(ans % 2 == 1) cout << ans/2 << ".5" << endl;
	else cout << ans/2 << endl;
}