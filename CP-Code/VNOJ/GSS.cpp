#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)
#define int long long

const int inf = 1e12 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 50005;

using namespace std;

struct Data{
	ll sum,prefix,suffix,best;
};

int n,a[NMAX];
Data tree[NMAX << 2];

Data combine(Data l, Data r) {
	Data res;
	res.sum = l.sum + r.sum;
	res.prefix = max(l.prefix, l.sum + r.prefix);
	res.suffix = max(r.suffix, r.sum + l.suffix);
	res.best = max(max(l.best, r.best), l.suffix + r.prefix);
	return res;
}

void buildTree(int k, int l, int r) {
	if (l == r) {
		tree[k].sum = tree[k].prefix = tree[k].suffix = tree[k].best = (ll) a[l];
		return;
	}
	int m = (l+r)>>1;
	buildTree(k<<1, l, m);
	buildTree(k*2+1, m+1, r);
	tree[k] = combine(tree[k<<1], tree[k*2+1]);
}

Data findMax(int k, int l, int r, int L, int R) {
	if (r < L || R < l) return { 0ll, -inf, -inf, -inf };
	if (L <= l && r <= R) return tree[k];
	int m = (l+r)>>1;
	Data lt = findMax(k<<1, l, m, L, R);
	Data rt = findMax(k*2+1, m+1, r, L, R);
	return combine(lt, rt);
}


signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) cin >> a[i];
	buildTree(1,1,n);
	int q;
	cin >> q;
	while(q--) {
		int x,y;
		cin >> x >> y;
		cout << findMax(1,1,n,x,y).best << EL;
	}
	

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
