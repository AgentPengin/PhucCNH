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
const int NMAX = 10005;
const int bit[] = {0,1,2,4,5,8,9,10};

using namespace std;

int n,a[5][NMAX];
int f[NMAX][15];


signed main() {
	fastio
	cin >> n;
	int mx = -inf;
	for (int i = 1;i<=4;i++) {
		for (int j = 1;j<=n;j++){
			cin >> a[i][j];
			mx = max(mx,a[i][j]);
		}
	}
	if (mx < 0) {
		cout << mx;
		return 0;
	}
	for (int i = 1;i<=n;i++) {
		for (int j = 0;j<=7;j++) {
			int b = bit[j];
			f[i][b] = -inf;
			int tmp = 0;
			for (int k = 1;k<=4;k++) {
				b = bit[j];
				if ((b >> (4 - k)) & 1) tmp += a[k][i];
			}
			for (int l = 0;l<=7;l++) {
				if ((bit[j] & bit[l]) != 0) continue;
				f[i][bit[j]] = max(f[i-1][bit[l]] + tmp,f[i][bit[j]]);
			}				
		}
	}
	int res = -inf;
	for (int i = 0;i<=7;i++) {
		res = max(res,f[n][bit[i]]);
	}
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
