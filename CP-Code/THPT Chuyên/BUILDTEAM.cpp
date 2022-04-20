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
const int NMAX = 1e5 + 10;

using namespace std;

vector<int> adj[NMAX];
int check[NMAX];
int n,m;

void dfs(int u) {
	for (auto x : adj[u]) {
		if (check[x] == -1) {
			if (check[u] == 1) check[x] = 2;
			else check[x] = 1;
			dfs(x);
		} else {
			if (check[u] == 1 && check[x] == 1) {
				cout << "No";
				exit(0);
			}
			if (check[u] == 2 && check[x] == 2) {
				cout << "No";
				exit(0);
			}
		}
 	}
}

signed main() {
	fastio
	cin >> n >> m;
	for (int i = 1;i<=m;i++) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(check,-1,sizeof check);
	for (int i = 1;i<=n;i++) {
		if (check[i] == -1) {
			check[i] = 1;
			dfs(i);
		}
	}
	cout << "Yes";
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
    
