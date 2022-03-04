#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 1e5 + 10;
const int N = 2e5 + 10;

using namespace std;

ll n,k,l,a[NMAX];

bool cmp(ll a,ll b) {
	return a > b;
}

bool check(ll x) {
	ll needed = 0;
	for (ll j = 1;j<=x;j++) {
		needed += max(0LL,x - a[j]);
	}
	if (needed <= k * l && a[x] + k >= x) return true;
	else return false;
}

void solve() {
	ll left = 1,right = N,mid,res;
	while(left <= right) {
		ll mid = (left + right)/2;
		if (check(mid) == true) {
			res = mid;
			left = mid + 1;
		} else right = mid - 1;
	}
	cout << res;
}

signed main() {
	fastio
	cin >> n >> k >> l;
	for (ll i = 1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1,cmp);
	solve();			


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
