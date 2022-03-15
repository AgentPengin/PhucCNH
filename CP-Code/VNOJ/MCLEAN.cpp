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
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

using namespace std;

int m,n;
char c[22][22];
queue<pair<int,int>> q;
int dist[22][22];
int d[22][22],f[(1 << 13) + 5][22];
vector<pair<int,int>> v;

bool check_onboard(int x,int y) {
	if (x >= 1 && x <= m && y >= 1 && y <= n) return true;
	else return false;
}

void bfs(int id) {
	for (int i = 1;i<=m;i++) {
		for (int j = 1;j<=n;j++) {
			d[i][j] = -1;
		}
	}
	q.push(make_pair(v[id].fi,v[id].se));
	d[v[id].fi][v[id].se] = 0;
	while(!q.empty()) {
		int u = q.front().fi;
		int v = q.front().se;
		q.pop();
		for (int i = 0;i<4;i++) {
			int x = u + dx[i];
			int y = v + dy[i];
			if (!check_onboard(x,y)) continue;
			if (c[x][y] == 'x') continue;
			if (d[x][y] == -1) {
				d[x][y] = d[u][v] + 1;
				q.push(make_pair(x,y));
			}
			
		}
	}
	for (int i = 0;i<v.size();i++) {
		int x = v[i].fi;
		int y = v[i].se;
		dist[id][i] = d[x][y];
	}
}

signed main() {
	fastio
	while(true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		memset(dist,-1,sizeof(dist));
		v.clear();
		pair<int,int> start;
		for (int i = 1;i<=m;i++) {
			for (int j = 1;j<=n;j++) {
				cin >> c[i][j];
				if (c[i][j] == 'o') start = make_pair(i,j);
				if (c[i][j] == '*') v.push_back(make_pair(i,j));
			}
		}
		v.push_back(start);
		reverse(v.begin(),v.end());
		for (int i = 0;i<v.size();i++) {
				bfs(i);
		}		
		for (int i = 0;i<(1 << (v.size()));i++) {
			for (int j = 0;j<(v.size());j++) {
				f[i][j] = inf;
			}
		}
		for (int j = 1;j<v.size();j++) {
			if (dist[0][j] == -1) continue;
			f[(1 << j)|1][j] = dist[0][j];
		}
		int p = v.size();
		int res = inf;
		for (int mask = 0;mask < (1 << p);mask++) {
			for (int i = 0;i<p;i++) {
				if (!(mask >> i & 1)) continue;
				for (int j = 0;j<p;j++){
					if (!(mask >> j & 1)) continue;
					if (i == j) continue;
					if (dist[j][i] == -1) continue; 
					if (f[mask&~(1 << i)][j] == inf) continue;
					f[mask][i] = min(f[mask][i],f[mask&~(1 << i)][j] + dist[j][i]);
				}				
				if (__builtin_popcount(mask) == p) res = min(res,f[mask][i]);
			}
		}
		if (p == 1) cout << 0 << EL
		else if (res == inf) cout << -1 << EL
		else cout << res << EL;
	}

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
