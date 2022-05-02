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

using namespace std;

int n,a[100005],x;

signed main() {
	fastio
	cin >> n >> x;
	for (int i = 1;i<=n;i++) cin >> a[i];
	int res = 0;
	a[0] = 0;
	for (int i = 1;i<=n;i++) {
		if (a[i] + a[i-1] > x) {
			res += (a[i] + a[i-1] - x);
			a[i] = a[i] - (a[i] + a[i-1] - x);
		}
	}
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
