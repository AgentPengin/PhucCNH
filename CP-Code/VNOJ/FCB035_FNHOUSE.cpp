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
const ll NMAX = 1e3 + 2;
const ll dx[] = {-1,-1,-1,0,1,1,1,0};
const ll dy[] = {1,0,-1,-1,-1,0,1,1};


using namespace std;

ll m,n,total = 0,more = 0;
bool a[NMAX][NMAX];

ll numpairs(ll x,ll y) {
	ll cnt = 0;
	for (int i = 0;i<=7;i++) {
		cnt = cnt + a[x+dx[i]][y+dy[i]];
	}
	return cnt;
}

signed main() {
	fastio
	cin >> m >> n;
	for (int i = 1;i<=m;i++) {
		for (int j = 1;j<=n;j++) {
			char c;
			cin >> c;
			a[i][j] = (c == '#');
		}
	}

	for (int i = 1;i<=m;i++) {
		for (int j = 1;j<=n;j++) {
			if (a[i][j]) total = total + numpairs(i,j);
			else more = max(more,numpairs(i,j));
		}
	}
	cout << total/2 + more;
	

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
