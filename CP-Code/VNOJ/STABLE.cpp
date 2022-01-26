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
const int NMAX = 10001;

using namespace std;

int n,m,s;
vector<int> adj[NMAX];
map<pair<int,int>,bool> mp;
int len[NMAX],cnt[NMAX];
queue<int> q;

signed main() {
	fastio
	cin >> n >> m >> s;
	for (int i = 1;i<=m;i++) {
		int u,v;
		cin >> u >> v;
		if (mp[{u,v}]) continue;
		mp[{u,v}] = true;
		adj[u].push_back(v);
	}	
	len[s] = 0;
	cnt[s] = 1;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0;i<adj[u].size();i++) {
			int v = adj[u][i];
			if (cnt[v] == 0) {
				len[v] = len[u] + 1;
				cnt[v] = cnt[u];
				q.push(v);
			} else {
				if (len[v] == len[u] + 1) {
					if (cnt[v] == 1) cnt[v] = 2;
				}
			}
		}
	}
	int res = 0;
	for (int i = 1;i<=n;i++	) res += (cnt[i] == 2);
	cout << res;
	
	
	


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
