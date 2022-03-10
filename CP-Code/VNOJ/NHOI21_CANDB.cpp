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

int n,k;
int a[25][25];
int f[(1LL << 20) + 10];

signed main() {
	fastio
	cin >> n >> k;
	for (int i = 0;i<n;i++) {
		for (int j = 0;j<n;j++) {
			cin >> a[i][j];
		}
	}
	memset(f,0x3f,sizeof(f));
	f[(1LL << n) - 1] = 0;
	int res = inf;	
	for (int mask = (1LL << n) - 2;mask>0;mask--) {
		for (int i = 0;i<n;i++) {
			if (!(mask >> i & 1)) {
				for (int j = 0;j<n;j++) {
					if ((mask >> j) & 1) {
						f[mask] = min(f[mask],f[mask^(1LL << i)] + a[i][j]);
					}
				}
				
			}
		}
		if (__builtin_popcount(mask) == k) res = min(res,f[mask]);
	}
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
