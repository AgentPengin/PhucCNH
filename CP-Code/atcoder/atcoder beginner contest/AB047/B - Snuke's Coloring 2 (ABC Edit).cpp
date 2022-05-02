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

using namespace std;

int a[101][101];
int n,m,g;
pair<int,int> p[101];
bool axis_x[101];
bool axis_y[101];


signed main() {
	fastio
	cin >> n >> m >> g;
	for (int i = 1;i<=g;i++) {
		int request;
		cin >> p[i].fi >> p[i].se >> request;
		if (request == 1) {
			for (int j = 1;j<=p[i].fi;j++) axis_x[j] = true;
		} else if (request == 2) {
			for (int j = p[i].fi + 1;j<=n;j++) axis_x[j] = true;
		} else if (request == 3) {
			for (int j = 1;j<=p[i].se;j++) axis_y[j] = true;
		} else if (request == 4) {
			for (int j = p[i].se + 1;j<=m;j++) axis_y[j] = true;
		}
	}	
	//for (int i = 1;i<=m;i++) cout << axis_y[i] << EL;
	int res = 0;
	for (int i = 1;i<=m;i++) {
		for (int j = 1;j<=n;j++) {
			if (!axis_x[j] && !axis_y[i]) res++;
		}
	}
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
