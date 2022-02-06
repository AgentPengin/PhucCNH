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
const ll mod = 1e9 + 7;

using namespace std;

ll powerMod(ll n,ll k) {
	if (k == 0) return 1;
	if (k == 1) return n;
	ll tmp = powerMod(n,k/2) % mod;
	if (k % 2 == 0) return (tmp * tmp) % mod;
	else return ((tmp * tmp) % mod * n) % mod;
}


signed main() {
	fastio
	ll a,n;
	cin >> a >> n;
	ll aa = powerMod(a,n+1) - 1;
	ll b = a - 1;
	cout << (aa %mod * powerMod(b,mod-2)%mod)%mod;
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
