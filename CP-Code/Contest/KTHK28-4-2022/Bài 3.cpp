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

int m,n;
int a[1001][1001];
vector<pair<int,int>> va,vb;

signed main() {
	fastio
	cin >> n >> m;
	va.resize(n + 5);
	vb.resize(n + 5);
	for (int i = 1;i<=n;i++) {
		int mode_1 = 0,mode_2 = 0;
		for (int j = 1;j<=m;j++) {
			cin >> a[i][j];
			if (a[i][j] < 0) mode_2 += abs(a[i][j]);
			else if (a[i][j] > 0) mode_1 += a[i][j];
		}
		va.push_back(make_pair(mode_1,i));
		vb.push_back(make_pair(mode_2,i));
	}
	sort(va.begin(),va.end(),greater<pair<int,int>>());
	sort(vb.begin(),vb.end(),greater<pair<int,int>>());
	int res = 0;
	res = max(res,va[0].fi + vb[1].fi);
	res = max(res,vb[0].fi + vb[1].fi);
	if (va[0].se != vb[0].se) res = max(res,va[0].fi + vb[0].fi);
	else res = max({res,va[0].fi + vb[1].fi,va[1].fi + vb[0].fi});
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
