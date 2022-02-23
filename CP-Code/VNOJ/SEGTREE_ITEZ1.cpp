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
const int NMAX = 100005;


using namespace std;

int n,a[NMAX],tree[NMAX * 4];

void buildTree(int id,int left,int right) {
	if (left == right) {
		tree[id] = a[left];
		return;
	}
	int mid = (left + right)/2;
	buildTree(id*2,left,mid);
	buildTree(id*2+1,mid+1,right);
	tree[id] = max(tree[id*2],tree[id*2+1]);
}

void update(int id,int left,int right,int x,int y) {
	if (x > right || x < left) return;
	if (left == right) {
		tree[id] = y;
		return;
	}
	int mid = (left + right)/2;
	update(id*2,left,mid,x,y);
	update(id*2+1,mid+1,right,x,y);
	tree[id] = max(tree[id*2],tree[id*2+1]);
}

int getVal(int id,int left,int right,int u,int v) {
	if (u > right || v < left) return -inf;
	if (u <= left && v >= right) return tree[id];
	int mid = (left+right)/2;
	return max(getVal(id*2,left,mid,u,v),getVal(id*2+1,mid+1,right,u,v));
}

signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) cin >> a[i];
	buildTree(1,1,n);
	int q;
	cin >> q;
	while(q--) {
		int request,x,y;
		cin >> request >> x >> y;
		if (request == 1) update(1,1,n,x,y);
		else cout << getVal(1,1,n,x,y) << EL;
	}		
	time;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
