#include<bits/stdc++.h>
#define ll long long
#define EL '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int inf = 1e9 + 7;

using namespace std;

struct Edge{
	int u,v,w;
};

int n,m;
vector<Edge> edge;
int parent[1001],size[1001];
vector<Edge> mst;

bool cmp(Edge a,Edge b) {
	return a.w < b.w;
}

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

bool Union(int a,int b) {
	a = find_par(a);
	b = find_par(b);
	if (a == b) return false;
	if (size[a] < size[b]) swap(a,b);
	parent[b] = a;
	size[a] += size[b];
	return true;
}

signed main() {
	fastio
	if (ifstream("A.inp")) {
		freopen("A.inp","r",stdin);
		freopen("A.out","w",stdout);
	}
	cin >> n >> m;
	for (int i = 1;i<=m;i++) {
		int x,y,z;
		cin >> x >> y >> z;
		edge.push_back({x,y,z});
	}
	sort(edge.begin(),edge.end(),cmp);
	make_set();
	for (int i = 0;i<m;i++) {
		if (mst.size() == n - 1) break;
		Edge e = edge[i];
		if (Union(e.u,e.v)) {
			mst.push_back(e);
		}
	}
	int res = -inf;
	for (auto x : mst) {
		res = max(res,x.w);
	}
	cout << res;
	
	return 0;
}
