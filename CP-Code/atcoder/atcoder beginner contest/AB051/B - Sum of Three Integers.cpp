#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(val) "["#val" = "<<(val)<<"] "

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

signed main() {
	fastio
	ll k,s,cnt = 0;
	cin >> k >> s;
	for (ll x = 0;x<=k;x++) {
		for (ll y = 0;y<=k;y++) {
			if ((s - x - y) <= k && (s-x-y) >= 0) cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
