#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)
#define int long long

const int inf = 1e18 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 1e5 + 10;

using namespace std;

int m,n,k;
int a[NMAX],b[NMAX],c[NMAX];
int tree[NMAX << 2];

void buildTree(int id,int left,int right) {
	if (left == right) {
		tree[id] = c[left];
		return;
	}
	int mid = (left + right) >> 1;
	buildTree(id << 1,left,mid);
	buildTree((id << 1) + 1,mid + 1,right);
	tree[id] = min(tree[id << 1],tree[(id << 1) + 1]);
}

int getVal(int id,int left,int right,int u,int v) {
	if(u > right || v < left) return inf;
	if (u <= left && v >= right) return tree[id];
	int mid = (left + right) >> 1;
	return min(getVal(id << 1,left,mid,u,v),getVal((id << 1) + 1,mid + 1,right,u,v));
}

int Searching(int x) {
	ll p = lower_bound(b + 1,b + n + 1,x) - b;
	ll left = p - 1,right = p + 1;
	ll res = abs(b[p] - x);
	while(left >= 1 && abs(b[left] - x) < res) res = abs(b[left] - x),left--;
	while(right <= n && abs(b[right] - x) < res) res = abs(b[right] - x),right++;
	return res;
}

signed main() {
	fastio
	cin >> m >> n >> k;
	for (int i = 1;i<=m;i++) cin >> a[i];
	for (int i = 1;i<=n;i++) cin >> b[i];
	sort(b+1,b+n+1);
	for (int i = 1;i<=m;i++) {
		int _k = Searching(a[i]);
		c[i] = _k;
	}
	buildTree(1,1,m);
	for (int i = 1;i<=k;i++) {
		int x,y;
		cin >> x >> y;
		//cerr << x << " " << y << EL;
		cout << getVal(1,1,m,x,y) << EL;
	}
		
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
