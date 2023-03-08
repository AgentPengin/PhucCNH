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

const int inf = 1e9 + 7;
const int N = 1e4 + 5;

int n,city[N],dist[N],s,m;
vector<pair<int,int>> adj[N];
vector<int> radj[N];
bool mark[N];
deque<pair<int,int>> dq;

void dijkstra(int u) {
	for (int i = 1;i <= n;i++) {
		dist[i] = inf;
	}
	dist[u] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({dist[u],u});
	while(!pq.empty()) {
		int u = pq.top().se;
		int du = pq.top().fi;
		pq.pop();
		if (dist[u] != du) continue;
		for (auto it : adj[u]) {
			int v = it.se;
			int uv = it.fi;
			if (du + uv < dist[v]) {
				dist[v] = du + uv;
				pq.push({dist[v],v});
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		if (i != u && dist[i] <= 600 && (mark[i] || i == 1 || i == n)) {
			radj[u].push_back(i);
			radj[i].push_back(u);
		}
	}
}

void bfs(int node) {
	for (int i = 1;i <= n;i++) {
		dist[i] = inf;
	}
	dist[node] = 0;
	dq.push_back({0,node});
	while(!dq.empty()) {
		int du = dq.front().fi;
		int u = dq.front().se;
		dq.pop_front();
		if (dist[u] != du) continue;
		for (auto v : radj[u]) {
			if (dist[v] > du + 1) {
				dist[v] = du + 1;
				dq.push_back({dist[v],v});
			}
		}
	}
	if (dist[n] == inf) cout << -1 << EL;
	else {
		dist[n]--;
		cout << dist[n] << EL;
	}
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    while(true) {
	    cin >> n;
	    if (n == 0) break;
	    cin >> s;
	    for (int i = 1;i <= n;i++) {
	    	mark[i] = false;
	    	adj[i].clear();
	    	radj[i].clear();
	    }
	    for (int i = 1;i <= s;i++) {
	    	cin >> city[i];
	    	mark[city[i]] = true;
	    }
	    cin >> m;
	 	for (int i = 1;i <= m;i++) {
	 		int u,v,c;
	 		cin >> u >> v >> c;
	 		adj[u].push_back({c,v});
	 		adj[v].push_back({c,u});
	 	}
	 	for (int i = 1;i <= s;i++) {
	 		dijkstra(city[i]);
	 	}
	 	dijkstra(1);
	 	// for (int i = 1;i <= n;i++) {
	 		// cerr << i << " ";
	 		// for (auto v : radj[i]) cerr << v << " ";
	 		// cerr << EL;
	 	// }
 		bfs(1);
	}
    return 0;
}
// agent pengin wants to take apio (with anya-san)
