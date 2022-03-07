#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)

const ll inf = 1e18 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const ll NMAX = 1e7 + 1;


using namespace std;

ll n,m,k,x,q;
ll a[NMAX],prefix[NMAX],suffix[NMAX],best = -inf;

signed main() {
	fastio
	cin >> n >> m >> k >> x >> q;
	a[1] = x;
	for (ll i = 2;i<=n;i++) a[i] = (a[i-1] * k) % m;
	prefix[0] = -inf;
	suffix[n+1] = -inf;
	for (ll i = 1;i<=n;i++) {
		a[i] -= q;
		best = max(best,a[i]);
		prefix[i] = max(prefix[i-1],a[i]);
	}
	for (ll i = n;i>=1;i--) {
		suffix[i] = max(suffix[i+1],a[i]);
	}
	int test;
	cin >> test;
	while(test--) {
		ll l,r,d;
		cin >> l >> r >> d;
		cout << max({prefix[l-1],suffix[r+1],best - d}) << EL;
	}
	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
