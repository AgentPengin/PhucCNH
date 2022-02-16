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

int n,m;
int a[105][105];
pair<int,int> starter,ender;
queue<pair<int,int>> q;
map<pair<int,int>, bool> P;
map<pair<int,int>,int> path;
map<pair<int,int>,pair<int,int>> trace;
bool check = false;

signed main() {
	fastio
	cin >> n >> m;
	for (int i = 1;i<=n;i++) {
		for (int j = 1;j<=m;j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) starter = {i,j};
			if (a[i][j] == 3) ender = {i,j};
		} 
	}
	P[ender] = true;
	q.push(ender);
	trace[ender] = ender;
	path[ender] = 1;
	while(!q.empty() && !check) {
		pair<int,int> u = q.front();
		q.pop();
		for (int i = 0;i<4;i++) {
			int x = u.fi + dx[i];
			int y = u.se + dy[i];
			pair<int,int> v = {x,y};
			if (x < 1 || y < 1 || x > n || y > m || P[v] == true || a[x][y] == 1) continue;
			trace[v] = u;
			path[v] = path[u] + 1;
			q.push(v);
			P[v] = true; 
			if (v == starter) {
				path[starter] = path[v];
				trace[starter] = trace[v];
				check = true;
				break;
			}
		}
		
	}
	cout << path[starter] << EL;
	pair<int,int> u = trace[starter];
	cout << starter.fi << " " << starter.se << EL;
	while(u != ender) {
		cout << u.fi << " " << u.se << EL;
		u = trace[u];
	}
	cout << ender.fi << " " << ender.se << EL;

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
