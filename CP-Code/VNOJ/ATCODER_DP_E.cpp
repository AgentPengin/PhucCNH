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

using namespace std;

int n,w;
int f[101][100001]; // f[i][j] the minimum weight at index i with the value j 
pair<int,int> a[101];


signed main() {
	fastio
	cin >> n >> w;
	for (int i = 1;i<=n;i++) cin >> a[i].fi >> a[i].se;
	for (int i = 1;i<=100;i++) {
		for (int j = 1;j<=100000;j++) f[i][j] = inf;
	}
	f[0][0] = 0;
	f[1][a[1].se] = a[1].fi;
	for (int i = 2;i<=n;i++) {
		f[i][0] = 0;
		for (int j = 1;j<=100000;j++) {
			f[i][j] = f[i-1][j];
			if (j >= a[i].se) {
				f[i][j] = min(f[i][j],f[i-1][j - a[i].se] + a[i].fi);
			}
		}
	}
	ll res = inf;
	for (int i = 100000;i>=0;i--) {
		if (f[n][i] <= w) {
			cout << i;
			return 0;
		}
	}
	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
