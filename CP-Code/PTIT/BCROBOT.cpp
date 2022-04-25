#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)

const ll mod = 2147483647;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

using namespace std;

int n;
ll dp[1001][1001];
char a[1001][1001];
queue<pair<int,int>> q;
bool check[1001][1001];

bool check_onboard(int x,int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) {
		for (int j = 1;j<=n;j++) cin >> a[i][j];
	}
	// dp
	if (a[1][1] == '.') dp[1][1] = 1LL;
	else dp[1][1] = 0LL;
	for (int i = 2;i<=n;i++) {
		if (a[1][i] == '#') dp[1][i] = 0LL;
		else dp[1][i] = dp[1][i-1];
	}
	for (int i = 2;i<=n;i++) {
		if (a[i][1] == '#') dp[i][1] = 0LL;
		else dp[i][1] = dp[i-1][1];
	}
	for (int i = 2;i <= n;i++) {
		for (int j = 2;j<=n;j++) {
			if (a[i][j] == '#') dp[i][j] = 0LL;
			else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
		}
	}
	if (dp[n][n] != 0) cout << dp[n][n];
	else {
		//BFS
		q.push({1,1});
		check[1][1] = true;
		while(!q.empty()) {
			pair<int,int> t = q.front();
			q.pop();
			if (a[t.fi][t.se] == '#') continue;
			if (t.fi == n && t.se == n) {
				cout << "THE GAME IS A LIE";
				return 0;
			}
			for (int i = 0;i<4;i++) {
				int x = t.fi + dx[i];
				int y = t.se + dy[i];
				if (!check_onboard(x,y) || a[x][y] == '#' || check[x][y] == true) continue;
				q.push({x,y});
				check[x][y] = true;
			}
		}
		cout << "INCONCEIVABLE";
	}
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
