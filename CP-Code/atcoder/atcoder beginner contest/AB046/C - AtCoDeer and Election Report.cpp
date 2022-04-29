#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(val) "["#val" = "<<(val)<<"] "
#define int long long

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 1001;

using namespace std;

int n;
pair<int,int> a[NMAX];

signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) cin >> a[i].fi >> a[i].se;
	pair<int,int> now = make_pair(1,1);
	for (int i = 1;i<=n;i++) {
		int _a = a[i].fi / __gcd(a[i].fi,a[i].se);
		int _b = a[i].se / __gcd(a[i].fi,a[i].se);
		int tmp1 = now.fi / _a,tmp2 = now.se / _b;
		if (now.fi % _a != 0) tmp1++;
		if (now.se % _b != 0) tmp2++;
		int k = max(tmp1,tmp2);
		now.fi = _a * k;
		now.se = _b * k;
	}
	cout << now.fi + now.se;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
