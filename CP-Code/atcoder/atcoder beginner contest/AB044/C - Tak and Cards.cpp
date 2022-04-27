#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(val) "["#val" = "<<(val)<<"] "

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

int n,a;
int x[51];
ll dp[51][51][51*51];
int sum = 0;

signed main() {
	fastio
	cin >> n >> a;
	for (int i = 1;i<=n;i++) cin >> x[i],sum += x[i];
	for (int i = 0;i<=n;i++) dp[i][0][0] = 1;
	for (int i = 1;i<=n;i++) {
		for (int k = 1;k<=i;k++) {
			for (int s = 1;s <= sum;s++) {
				if (s >= x[i]) dp[i][k][s] = dp[i-1][k][s] + dp[i-1][k-1][s - x[i]];
				else dp[i][k][s] = dp[i-1][k][s];
			}
		}  
	}
	ll res = 0;
	for (int i = 1;i<=n;i++) {
		res += dp[n][i][i * a];
	}
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
