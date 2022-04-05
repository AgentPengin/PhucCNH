#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)
#define int long long

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

int n,parent[1001],size[1001],enemy[1001];

void make_set() {
	for (int i = 1;i<=n;i++) {
		parent[i] = i;
		size[i] = 1;
	}
}

int find_par(int v) {
	if (v == parent[v]) return v;
	return parent[v] = find_par(parent[v]);
}

void Union(int u,int v) {
	u = find_par(u);
	v = find_par(v);
	if (u != v) {
		if (size[u] < size[v]) swap(u,v);
		parent[v] = u;
		size[u] += size[v];
	}
}

signed main() {
	fastio
	cin >> n;
	make_set();
	int m;
	cin >> m;
	for (int i = 0;i<m;i++) {
		char c;
		int u,v;
		cin >> c >> u >> v;
		if (c == 'F') Union(u,v);
		else {
			if (enemy[v]) Union(u,enemy[v]);
			if (enemy[u]) Union(enemy[u],v);
			enemy[u] = v;
			enemy[v] = u;
			
		} 
	}
	set<int> s;
	int res = 0;
	for (int i = 1;i<=n;i++) {
		if (parent[i] == i) res++;
	}
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
