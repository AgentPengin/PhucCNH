// Problem: A. Cupboards
// Contest: Codeforces - Codeforces Round #152 (Div. 2)
// URL: https://codeforces.com/problemset/problem/248/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

using namespace std;

signed main() {
	fastio
	int n;
	cin >> n;
	pair<int,int> a[10001];
	int close_all = 0,open_all = 0,left_close = 0,right_close = 0;
	for (int i = 1;i<=n;i++) {
		cin >> a[i].fi >> a[i].se;
	}
	pair<int,int> b[10001],c[10001],d[10001],e[10001];
	
	for (int i = 1;i<=n;i++) {
		b[i].fi = 0;
		b[i].se = 0;
	}
	for (int i = 1;i<=n;i++) {
		c[i].fi = 1;
		c[i].se = 1;
	}
	for (int i = 1;i<=n;i++) {
		d[i].fi = 1;
		d[i].se = 0;
	}
	for (int i = 1;i<=n;i++) {
		e[i].fi = 0;
		e[i].se = 1;
	}
	for (int i = 1;i<=n;i++) {
		if (a[i].fi != b[i].fi) close_all++;
		if (a[i].se != b[i].se) close_all++;
		if (a[i].fi != c[i].fi) open_all++;
		if (a[i].se != c[i].se) open_all++;
		if (a[i].fi != d[i].fi) left_close++;
		if (a[i].se != d[i].se) left_close++;
		if (a[i].fi != e[i].fi) right_close++;
		if (a[i].se != e[i].se) right_close++;
 	}
	cout << min({left_close,right_close,open_all,close_all});

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
