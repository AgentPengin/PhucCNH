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

int n;
int a[3001];
int f[3001][3001];

signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) cin >> a[i];
	int res = 0;
	for (int i = 1;i<=n-1;i++) {
		for (int j = n;j>=i+1;j--) {
			if (a[i] != a[j]) f[i][j] = max(f[i-1][j+1] + a[i] * a[j],a[i] * a[j]);
			res = max(res,f[i][j]);
		}
	}
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
