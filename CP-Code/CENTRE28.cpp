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
const int NMAX = 30005;

using namespace std;

int n,m;
vector<pair<int,int>> adj[NMAX];
int d1[NMAX],g1[NMAX],d2[NMAX],g2[NMAX];

void read() {
	cin >> n >> m;
	int u,v,l;
	for (int i = 1;i<=m;i++) {
		cin >> u >> v >> l;
		adj[u].push_back(make_pair(l,v));
		adj[v].push_back(make_pair(l,u));
	}
}

void dijkstra_1() {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
	d1[1] = 0;
	g1[1] = 1;
	for (int i = 2;i<=n;i++) d1[i] = inf;
	min_heap.push(make_pair(d1[1],1));
	while(!min_heap.empty()) {
		pair<int,int> t = min_heap.top();
		min_heap.pop();
		int u = t.se;
		if (d1[u] < t.fi) continue;
		for (auto k : adj[u]) {
			int v = k.se, l = k.fi;
			if (d1[v] < d1[u] + l) continue;
			if (d1[v] > d1[u] + l) {
				d1[v] = d1[u] + l;
				g1[v] = g1[u];
				min_heap.push({d1[v],v});
			} else g1[v] += g1[u];	
		}	
	}
}

void dijkstra_2() {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
	d2[n] = 0;
	g2[n] = 1;
	for (int i = 1;i<=n-1;i++) d2[i] = inf;
	min_heap.push({d2[n],n});
	while(!min_heap.empty()) {
		pair<int,int> t = min_heap.top();
		min_heap.pop();
		int u = t.se;
		if (d2[u] < t.fi) continue;
		for (auto k : adj[u]) {
			int v = k.se, l = k.fi;
			if (d2[v] < d2[u] + l) continue;
			if (d2[v] > d2[u] + l) {
				d2[v] = d2[u] + l;
				g2[v] = g2[u];
				min_heap.push({d2[v],v});
			} else g2[v] += g2[u];
		}
	}
}

signed main() {
	fastio
	read();
	dijkstra_1();
	dijkstra_2();
	vector<int> res;
	for (int i = 2;i<=n-1;i++) {
		if (d1[i] + d2[i] > d1[n] || g1[i] * g2[i] < g1[n]) res.push_back(i);
	}
	cout << res.size() << EL;
	for (int i = 0 ;i<res.size();i++) cout << res[i] << EL;
	
	
	

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
