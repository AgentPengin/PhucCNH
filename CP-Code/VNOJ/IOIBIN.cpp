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

int p;
int parent[50005],size[50005];
int n = 10000;

void make_set() {
	for (int i = 1;i<=n;i++){
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
	if (a == b) return true;
	if (size[a] < size[b]) swap(a,b);
	parent[b] = a;
	size[a] += size[b];
	return false;
} 

signed main() {
	fastio
	cin >> p;
	make_set();
	while(p--) {
		int x,y,z;
		cin >> x >> y >> z;
		if (z == 1) {
			Union(x,y);
		} else {
			if (find_par(x) == find_par(y)) cout << 1 << EL
			else cout << 0 << EL;
		}
	}

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
