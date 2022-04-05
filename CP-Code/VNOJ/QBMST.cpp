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

struct Edge{
	int u,v,w;
};

int n,m,size[10005],parent[10005];
vector<Edge> edge;
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

bool Union(int a,int b){
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
	cin >> n >> m;
	for (int i = 1;i<=m;i++) {
		int x,y,z;
		cin >> x >> y >> z;
		edge.push_back({x,y,z});
	}
	sort(edge.begin(),edge.end(),cmp);
	make_set(); 
	int res = 0;
	for (int i = 0;i<edge.size();i++) {
		if (Union(edge[i].u,edge[i].v)) {
			mst.push_back({edge[i].u,edge[i].v,edge[i].w});
			res += edge[i].w;
		}
	}
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
