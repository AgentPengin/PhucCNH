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

using namespace std;

signed main() {
	fastio
	ll a,b,c,n;
	cin >> a >> b >> c >> n;
	// x + z = a -> 
	ll x = a - c;
	ll y = b - c;
	if (x < 0 || y < 0 ) {
		cout << -1;
		return 0;
	}
	ll res = n - (x+y+c);
	if (res < 1) {
		cout << -1;
		return 0;
	}
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
