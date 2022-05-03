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
const int NMAX = 2 * 1e5 + 10;

using namespace std;

int n,k,l;
vector<int> adj[NMAX];
vector<int> bdj[NMAX];
int road[NMAX],rail[NMAX];
int state = 0;

void dfs_road(int u) {
	road[u] = state;
	for (auto x : adj[u]) {
		if (!road[x]) dfs_road(x);
	}
}

void dfs_rail(int u) {
	rail[u] = state;
	for (auto x : bdj[u]) {
		if (!rail[x]) dfs_rail(x);
	}
}

signed main() {
	fastio
	cin >> n >> k >> l;
	for (int i = 1;i<=k;i++) {
		int u,v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1;i<=l;i++) {
		int u,v;
		cin >> u >> v;
		bdj[u].push_back(v);
		bdj[v].push_back(u);
	}	
	for (int i = 1;i<=n;i++) {
		if (!road[i]) {
			state++;
			dfs_road(i);
		}
		if (!rail[i]) {
			state++;
			dfs_rail(i);
		}
	}
	map<pair<int,int>,int> mp;
	for (int i = 1;i<=n;i++) mp[{road[i],rail[i]}]++;
	for (int i = 1;i<=n;i++) cout << mp[{road[i],rail[i]}] << " ";
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
