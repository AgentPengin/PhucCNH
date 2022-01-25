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
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

using namespace std;

int n,height_max = -1,height_min = 111;
int a[101][101];
int Free[101][101];

bool bfs(int curr) {
	for (int left = height_min;left <= height_max - curr;left++) {
		int right = left + curr;
		if (a[1][1] < left || a[1][1] > right) continue;
		for (int i = 1;i<=n;i++) {
			for (int j = 1;j<=n;j++) Free[i][j] = 0;
		}
		Free[1][1] = 1;
		queue<pair<int,int>> q;
		q.push({1,1});
		while(!q.empty()) {
			int i = q.front().fi;
			int j = q.front().se;
			q.pop();
			if (i == n && j == n) return true;
			for (int k = 0;k<=3;k++) {
				int u = i + dx[k];
				int v = j + dy[k];
				if (u < 1 || u > n || v < 1 || v > n) continue;
				if (a[u][v] < left || a[u][v] > right || Free[u][v] == 1) continue;
				Free[u][v] = 1;
				q.push({u,v}); 	
			}	
		}
	}
	return false;	
}
signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) {
		for (int j = 1;j<=n;j++) {
			cin >> a[i][j];
			height_max = max(height_max,a[i][j]);
			height_min = min(height_min,a[i][j]);
		}
	}
	int left = 0;
	int right = height_max - height_min;
	int res = 0;
	while(left <= right) {
		int mid = (left + right)/2;
		if (bfs(mid) == true) {
			res = mid;
			right = mid - 1;
		} else left = mid + 1;
	}
	cout << res;
	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
