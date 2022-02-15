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

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
int n,m,k,S,T,d[105],trace[105];
vector<pair<int,int>> adj[105];
vector<int> path;

void dijkstra() {
	for (int i = 1;i<=n;i++) d[i] = inf;
	d[S] = 0;
	q.push(make_pair(d[S],S));
	while(!q.empty()) {
		int u = q.top().se;
		int l = q.top().fi;
		q.pop();
		if (d[u] != l) continue;
		for (auto x : adj[u]) {
			int v = x.se;
			int c = x.fi;
			if (d[v] > d[u] + c) {
				d[v] = d[u] + c;
				trace[v] = u;
				q.push({d[v],v});
			}
		}
	}
}

void request0() {
	if (d[T] == inf) {
		cout << -1 << EL;
	} else {
		cout << d[T] << EL;
	}
}

void request1() {
	path.clear();
	if (d[T] != inf) {
		while(true) {
			path.push_back(T);
			if (T == S) break;
 			T = trace[T];
			
			
		}
	}
	cout << path.size() << " ";
	for (int i = path.size() - 1;i>=0;i--) cout << path[i] << " ";
	cout << EL;
	
}


signed main() {
	fastio 
  	cin >> n >> m >> k;
  	for (int i = 1;i<=m;i++) {
  		int u,v,l;
  		cin >> u >> v >> l;
  		adj[u].push_back(make_pair(l,v));
  		adj[v].push_back(make_pair(l,u));
  	}
  	while(k--) {
  		int request;
  		cin >> request >> S >> T;
  		dijkstra();
		if (request == 0) request0();
		else request1();
		
		
  		
  	}
  	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
