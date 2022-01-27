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
const int N = 1e5;

using namespace std;

signed main() {
	fastio
	ll x;
	cin >> x;
	ll res = 1;
	for (int i = 2;i<=sqrt(N);i++) {
		ll tmp = i;
		//if (tmp <= x) res = max(res,tmp);
		for (int j = 1;j<=30;j++) {
			tmp = tmp * i;
			if (tmp <= x) res = max(res,tmp);
		}
	}
	cout << res;

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
