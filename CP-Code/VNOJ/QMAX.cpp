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
const int NMAX = 50005;

using namespace std;

int n,a[NMAX],m,p,tree[NMAX << 2];

void buildTree(int id,int left,int right) {
	if (left == right) {
		tree[id] = a[left];
		return;
	}
	int mid = (left + right) >> 1;
	buildTree(id << 1,left,mid);
	buildTree((id << 1) + 1,mid + 1,right);
	tree[id] = max(tree[id << 1],tree[(id << 1) + 1]);
}

int getVal(int id,int left,int right,int u,int v) {
	if (v < left || u > right) return -inf;
	if (u <= left && v >= right) return tree[id];
	int mid = (left + right) >> 1;
	return max(getVal(id << 1,left,mid,u,v),getVal((id << 1) + 1,mid+1,right,u,v));
}

signed main() {
	fastio
	cin >> n >> m;
	while(m--) {
		int u,v,k;
		cin >> u >> v >> k;
		a[u] += k;
		a[v+1] -= k;
	}
	for (int i = 2;i<=n;i++) a[i] = a[i-1] + a[i];
	buildTree(1,1,n);
	cin >> p;
	while(p--) {
		int u,v;
		cin >> u >> v;
		cout << getVal(1,1,n,u,v) << EL;
	}
	

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
