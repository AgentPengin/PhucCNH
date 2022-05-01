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
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

using namespace std;

int n,m;
char c[101][101];
bool check[101][101];
int res = 0;
queue<pair<int,int>> q;

bool check_onboard(int x,int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

void bfs(int x,int y) {
	q.push(make_pair(x,y));
	check[x][y] = true;
	while(!q.empty()) {
		pair<int,int> u = q.front();
		q.pop();
		for (int i = 0;i<4;i++) {
			int _x = u.fi + dx[i];
			int _y = u.se + dy[i];
			if (!check[_x][_y] && check_onboard(_x,_y)) {
				check[_x][_y] = true;
				q.push({_x,_y});
			}
		}
	}
}

signed main() {
	fastio
	cin >> n >> m;
	for (int i = 1;i<=n;i++) {
		for (int j = 1;j<=m;j++) {
			cin >> c[i][j];
			if (c[i][j] == '.') check[i][j] = true;
		}
	}
	for (int i = 1;i<=n;i++) {
		for (int j = 1;j<=m;j++) {
			if (!check[i][j]) {
				res++;
				bfs(i,j);
			}
		}
	}
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
