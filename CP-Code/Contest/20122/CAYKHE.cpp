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

int n,m;
int a[1001],w[1001],v[1001];
int f[101][10001];

signed main() {
	fastio
	cin >> n >> m;
	for (int i = 1;i<=n;i++) cin >> w[i] >> v[i] >> a[i];
	memset(f,0,sizeof(f));
	for (int i = 1;i<=n;i++) {
		for (int j = 0;j<=m;j++) {
			f[i][j] = max(f[i-1][j],f[i][j]);
			for (int k = 1;k<=a[i];k++) {
				if (k * w[i] > j) break;
				f[i][j] = max(f[i][j],f[i-1][j - w[i] * k] + k * v[i]);
			}
		}
	}	
	cout << f[n][m];
	time;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
