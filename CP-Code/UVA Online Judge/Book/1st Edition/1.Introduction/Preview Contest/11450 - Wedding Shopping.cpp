/**
 *    author:  AgentPengin ( Độc cô cầu bại )
 *    created: 23.12.2022 10:08:02
 *    too lazy to update time
**/
#include<bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define EL '\n'
#define NAME "NAME"
#define db(x) cerr << #x << " == " << x << endl

using namespace std;

const ll inf = 1e9 + 7;
const int N = 1e5 + 5;

int a[22][22],n,m,sz[22];
bool dp[22][222];

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
	int test;
	cin >> test;
	while(test--) {
		cin >> m >> n;
		int sum = 0;
		for (int i = 1;i <= n;i++) {
			cin >> sz[i];
			int mn = INT_MAX;
			for (int j = 1;j <= sz[i];j++) {
				cin >> a[i][j];
				mn = min(mn,a[i][j]);
			}
			sort(a[i] + 1,a[i] + sz[i] + 1,greater<int>());
			sum += mn;
		}
		if (sum > m) {
			cout << "no solution" << EL;
			continue;
		}
		int ans_tmp = 0;
		for (int i = 1;i <= n;i++) {
			ans_tmp += a[i][1];
		}
		if (ans_tmp <= m) cout << ans_tmp << EL;
		else {
			memset(dp,false,sizeof dp);
			for (int i = 1;i <= sz[1];i++) {
				if (a[1][i] <= m) dp[1][a[1][i]] = true;
			}
			for (int i = 2;i <= n;i++) {
				for (int j = 1;j <= sz[i];j++) {
					for (int k = 1;k <= m;k++) {
						if (k - a[i][j] >= 0) {
							if (dp[i - 1][k - a[i][j]] == true) dp[i][k] = true;
						}
					}
				}	
			}
			for (int i = m;i >= 1;i--) {
				if (dp[n][i]) {
					cout << i << EL;
					break;
				}
			}
		}	
	} 	
    return 0;
}
// agent pengin wants to take apio (with anya-san)
