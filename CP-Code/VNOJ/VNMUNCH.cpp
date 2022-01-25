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
const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

using namespace std;

int n,m;
char a[101][101];
pair<int,int> pb,pc;
map<pair<int,int>,bool> trace;
map<pair<int,int>,int> res;
queue<pair<int,int>> st;

signed main() {
	fastio
	cin >> n >> m;
	for (int i = 1;i<=n;i++) {
		for (int j = 1;j<=m;j++) cin >> a[i][j];
	}	
	for (int i = 1;i<=n;i++) {
		for (int j = 1;j<=m;j++) {
			if (a[i][j] == 'B') pb = {i,j};
			else if (a[i][j] == 'C') pc = {i,j};
		}
	}
	st.push(pc);
	trace[pc] = true;
	res[pc] = 1;
	bool found = false;
	while(!st.empty() && !found) {
		pair<int,int> p = st.front();
		st.pop();
		for (int k = 0;k<=3;k++) {
			int nx = p.fi + dx[k];
			int ny = p.se + dy[k];
			pair<int,int> np = {nx,ny};
			if (nx < 1 || nx > n || ny < 1 || ny > m || trace[np] || a[nx][ny] == '*') {
				continue;
			}
			if (np == pb) {
				res[pb] = res[p];
				found = true;
				break;
			}
			trace[np] = true;
			st.push(np);
			res[np] = res[p] + 1;
		}
	}
	cout << res[pb];
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
