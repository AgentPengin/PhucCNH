#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)
#define int long long
#define pipii pair<int,pair<int,int>> 

const int inf = 1e12 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 205;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

using namespace std;

struct cmp{
bool operator() (pipii u,pipii v) {
	return u.fi > v.fi;
}
};

int n,m;
int a[205][205];
map<pair<int,int>,int> d;

bool check_onboard(int x,int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= m) return true;
	else return false;
}

void dijkstra() {
	
	priority_queue<pipii,vector<pipii>,cmp> q;
	for (int i = 1;i<=n;i++) { 
		for (int j = 1;j<=m;j++) {
			d[{i,j}] = inf;
		}
	}
	for (int i = 1;i<=n;i++) {
		d[{i,1}] = a[i][1];
		q.push({d[{i,1}],make_pair(i,1)});
	}
	//q.push({0,make_pair(S,T)});
	while(!q.empty()) {
		pair<int,int> u = q.top().se;
		int du = q.top().fi;
		q.pop();
		if (du != d[u]) continue;
		
		for (int k = 0;k<4;k++) {
			int x = u.fi + dx[k];
			int y = u.se + dy[k];
			if (check_onboard(x,y)) {
				if (d[{x,y}] > a[x][y] + du) {
					d[{x,y}] = a[x][y] + du;
					q.push({d[{x,y}],make_pair(x,y)});
				}
			}
		}	
	}
	
}

signed main() {
	fastio
	cin >> n >> m;
	for (int i = 1;i<=n;i++) {
		for (int j = 1;j<=m;j++) cin >> a[i][j];
	}
	int res = inf;
	dijkstra();
	
	
	for (int i = 1;i<=n;i++) {
		for (int j = 1;j<=n;j++) {
			res = min(res,d[{j,m}]);
		}
	}
	
	
	cout << res;
	
	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
