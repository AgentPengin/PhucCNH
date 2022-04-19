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
const int NMAX = 100001;

using namespace std;

int n,a[NMAX];
int dp[2][NMAX];

signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) cin >> a[i];
	int res = -1;
	a[0] = -1e9;
	for (int i = 1;i<=n;i++) {
		if (a[i] > a[i-1]) {
			dp[0][i] = dp[0][i-1] + 1;
			dp[1][i] = dp[1][i-1] + 1;
		} else {
			dp[0][i] = 1;
			dp[1][i] = 1;
		}
		if (i > 1) {
			if (a[i] > a[i-2] + 1) dp[1][i] = max(dp[1][i],dp[0][i-2] + 2);
			res = max(res,dp[1][i]);
			res = max(res,min(dp[0][i] + 1,n));
		}
	}
	cout << res;
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
    
