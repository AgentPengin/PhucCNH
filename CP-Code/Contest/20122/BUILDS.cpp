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
const int NMAX = 2 * 1e5 + 10;

using namespace std;

pair<int,int> a[NMAX];
int n,res = 0;
int f[NMAX];
bool check[NMAX];

signed main() {
	fastio
	cin >> n;
	memset(check,true,sizeof(check));
	for (int i = 1;i<=n;i++) cin >> a[i].fi >> a[i].se;
	sort(a+1,a+n+1);
	f[0] = -1;
	for (int i = 1;i<=n;i++) {
		f[i] = max(f[i-1],a[i].se + a[i].fi);
	}	
	for (int i = 1;i<=n;i++) {
		if (a[i].fi + a[i].se <= f[i-1]) check[i] = false;
	}
	f[n+1] = -inf;
	for (int i = n;i>=1;i--) f[i] = max(f[i+1],a[i].se - a[i].fi);
	for (int i = 1;i<=n;i++) if (a[i].se - a[i].fi <= f[i+1]) check[i] = false;
	for (int i = 1;i<=n;i++) if (check[i] == true) res++;
	cout << res;
	time;

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
