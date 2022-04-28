#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(val) "["#val" = "<<(val)<<"] "

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 2e5 + 10;

using namespace std;

int n,q;
int a[NMAX];
bool check[NMAX];
int step[NMAX];

void dfs(int u) {
	clog << db(u) << EL;
	check[u] = true;
	if (u == a[u]) step[u] = 1;
	else {
		if (!check[a[u]]) {
			int v = a[u];
			dfs(v);
			if (step[v] != 0) step[u] = step[v] + 1;
			else step[u] = 0;
		} else {
			if (step[a[u]] != 0) step[u] = step[a[u]] + 1;
			else step[u] = 0;
		}
	}
}

signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) cin >> a[i];
	for (int i = 1;i<=n;i++) dfs(i);
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		if (step[x] == 0) cout << -1 << " ";
		else cout << step[x] << " ";
	}
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
