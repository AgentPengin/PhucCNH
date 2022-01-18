#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)
#define int long long

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 4 * 1e5 + 10;

using namespace std;



pair<int,int> a[NMAX*2];

bool cmp(pair<int,int> u,pair<int,int> v) {
	return u.fi - u.se < v.fi - v.se;
}

signed main() {
	fastio
	int n,res = 0;
	cin >> n;
	n *= 2;
	for (int i = 1;i<=n;i++) cin >> a[i].fi >> a[i].se;
	sort(a+1,a+n+1,cmp);
	for (int i = 1;i<=n/2;i++) res += a[i].fi;
	for (int i = n/2 + 1;i<=n;i++) res += a[i].se;
	cout << res;


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
