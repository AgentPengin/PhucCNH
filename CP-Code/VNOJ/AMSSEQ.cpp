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
const int NMAX = 1e4 + 10;

using namespace std;

int n,k;
int a[NMAX],f[NMAX];
int res = -inf;

signed main() {
	fastio
	cin >> n >> k;
	for (int i = 1;i<=n;i++) cin >> a[i];
	f[0] = 0;
	f[1] = a[1];
	for (int i = 2;i<=n;i++) {
		f[i] = -inf;
		for (int j = i-1;j>=max(0,i - k);j--) {
			f[i] = max(f[i],f[j]);
		}
		f[i] = f[i] + a[i];
		db(f[i]);
		res = max(f[i],res);
	}
	cout << res;

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
