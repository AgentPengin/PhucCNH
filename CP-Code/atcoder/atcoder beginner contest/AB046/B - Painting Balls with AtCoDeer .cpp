#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(val) "["#val" = "<<(val)<<"] "
#define int long long

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

int dp[1001][1001];
int s[1001],k,n;

signed main() {
	fastio
	cin >> n >> k;
	for (int i = 1;i<=k;i++) {
		dp[1][i] = 1;
	}
	s[1] = k;
	for (int i = 2;i<=n;i++) {
		for (int j = 1;j<=k;j++) {
			dp[i][j] = s[i-1]  - dp[i-1][j];	
			s[i] += dp[i][j];
		}
	}
	cout << s[n];
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
