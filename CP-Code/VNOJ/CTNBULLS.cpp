#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)
#define int long long

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int mod = 2111992;
const int NMAX = 1e5 + 10;

using namespace std;

int f[NMAX];

signed main() {
	fastio
	int n,k;
	cin >> n >> k;
	for (int i = 1;i<=k + 1;i++) {
		f[i] = (i + 1) % mod;
	}
	for (int i = k + 2;i<=n;i++) {
		f[i] = (f[i - k - 1] % mod + f[i-1] % mod) % mod;
	}
	cout << f[n];

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
