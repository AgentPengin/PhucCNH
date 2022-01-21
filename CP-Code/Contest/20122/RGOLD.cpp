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

int n,t;
pair<int,int> a[10001];
int f[10001][3001];

signed main() {
	fastio
	cin >> n >> t;
	for (int i = 1;i<=n;i++) cin >> a[i].fi >> a[i].se;
	sort(a+1,a+n+1);
	for (int i = 1;i<=n;i++) {
		for (int j = 1;j<=t;j++) {
			f[i][j] = max(f[i][j],f[i-1][j]);
			if (j > a[i].fi) f[i][j] = max(f[i][j],f[i-1][j-a[i].fi] + a[i].se);
 		}
	}
	int res = 0;
	for (int i = 1;i<=n;i++) {
		res = max(res,f[i-1][t] + a[i].se);
	}
	cout << res;
	

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
