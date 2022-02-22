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
int x[10001],dist[101][101];
vector<pair<int,int>> adj[101];

signed main() {
	fastio
	cin >> n >> m;
	for (int i = 1;i<=m;i++) cin >> x[i];
	for (int i = 1;i<=n;i++) {
		for (int j = 1;j<=n;j++) {
			int c;
			cin >> c;
			dist[i][j] = c;		
			adj[i].push_back(make_pair(j,c));
		}
	}
	for (int k = 1;k<=n;k++) {
		for (int u = 1;u<=n;u++) {
			for (int v = 1;v<=n;v++) {
				dist[u][v] = min(dist[u][v],dist[u][k] + dist[k][v]);
 			}
		}
	}
	ll res = 0;
	for (int i = 1;i<=m-1;i++) {
		res = res + dist[x[i]][x[i+1]];
	}
	res += dist[1][x[1]] + dist[x[m]][n];
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
