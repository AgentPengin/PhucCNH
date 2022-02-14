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
const int N = 5005;
const ll MAXD = 1e12 + 5;

using namespace std;

struct dat {
	int u;
	ll d;
	bool operator < (const dat &o) const {
		return d > o.d;
	}
};

int n,m;
ll d[N],f[N];
vector<pair<int,int>> adj[N];
priority_queue<dat> st;

void read() {
	cin >> n >> m;
	int k,u,v,l;
	for (int i = 1;i<=m;i++) {
		cin >> k >> u >> v >> l;
		adj[u].push_back({v,l});
		if (k == 2) adj[v].push_back({u,l});
	}
}

void solve() {
	d[1] = 0;
	f[1] = 1;
	for (int i = 2;i<=n;i++) d[i] = MAXD;
	st.push({1,d[1]});
	while(!st.empty()) {
		dat t = st.top();
		st.pop();
		int u = t.u;
		if (d[u] < t.d) continue;
		for (auto k : adj[u]) {
			int v = k.fi,l = k.se;
			if (d[v] < d[u] + l) continue;
			if (d[v] > d[u] + l) {
				d[v] = d[u] + l;
				f[v] = f[u];
				st.push({v,d[v]});  
			} else f[v] += f[u];
		}
	}
	cout << d[n] << " " << f[n];
}

signed main() {
	fastio
	read();
	solve();


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
