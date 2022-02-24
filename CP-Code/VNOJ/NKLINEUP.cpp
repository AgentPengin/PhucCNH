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
const int NMAX = 50005;

using namespace std;

struct DATA{
	int vmax,vmin;
} tree[NMAX << 2];

int n,a[NMAX],q;

DATA combine(DATA left,DATA right) {
	return {
		max(left.vmax,right.vmax),
		min(left.vmin,right.vmin)	
	};
}

void buildTree(int id,int left,int right) {
	if (left == right) {
		tree[id] = {a[left],a[left]};
		return;
	}
	int mid = (left + right)>>1;
	buildTree(id<<1, left,mid);
	buildTree((id << 1)+ 1,mid+1,right);
	tree[id] = combine(tree[id << 1],tree[(id << 1) + 1]);
}

int getValMax(int id,int left,int right,int u,int v) {
	if (v < left || u > right) return -inf;
	if (u <= left && v >= right) return tree[id].vmax;
	int mid = (left + right) >> 1;
	return max(getValMax(id << 1,left,mid,u,v),getValMax( (id << 1) + 1,mid+1,right,u,v));
}
int getValMin(int id,int left,int right,int u,int v) {
	if (v < left || u > right) return inf;
	if (u <= left && v >= right) return tree[id].vmin;
	int mid = (left + right) >> 1;
	return min(getValMin(id << 1,left,mid,u,v),getValMin( (id << 1)+ 1,mid+1,right,u,v));
}

signed main() {
	fastio
	cin >> n >> q;
	for (int i = 1;i<=n;i++) cin >> a[i];
	buildTree(1,1,n);	
	while(q--) {
		int x,y;
		cin >> x >> y;
		cout << abs(getValMax(1,1,n,x,y) - getValMin(1,1,n,x,y)) << EL;
	}

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
