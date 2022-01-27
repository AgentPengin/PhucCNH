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
	int test;
	cin >> test;
	while(test--) {
		ll m,n,x,y;
		cin >> n >> m >> x >> y;
		if (n < m) swap(m,n);
		if (m == 1) {
			cout << (n-1) * x << EL;
			continue;
		}
		ll t1 = (m + n - 2) * x;
		ll t2 = (n - m)*x + m*y-y;
		ll t3 = (n - (n - m)%2 -1) * y  + ((n - m) % 2) * x;
		cout << min({t1,t2,t3}) << EL;
	}

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
