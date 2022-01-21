#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)
#define int long long

const int inf = 1e18 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

int m,n;
int f[101][101];
int a[101][101];

signed main() {
	fastio
	cin >> m >> n;
	for (int i = 1;i<=m;i++) {
		for (int j = 1;j<=n;j++) cin >> a[i][j];
	}
	memset(f,-inf,sizeof(f));
	for (int j = 1;j<=n;j++) {
		f[1][j] = a[1][j];
	}
	for (int i = 2;i<=m;i++) {
		for (int j = 1;j<=n;j++) {
			f[i][j] = max({f[i-1][j+2],f[i-1][j-2],f[i-2][j-1],f[i-2][j+1]}) + a[i][j];
			//cout << f[i][j] << " ";
			}
		//cout << EL;
	}
	int res = -inf;
	for (int j = 1;j<=n;j++) {
		res = max(f[m][j],res);
	}
	cout << res;
	time;
	return 0;
}
// Code cua Minh Nhoẹt ༼ つ ◕_◕ ༽つ
