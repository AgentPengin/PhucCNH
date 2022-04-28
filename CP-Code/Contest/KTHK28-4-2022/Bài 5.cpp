#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(val) "["#val" = "<<(val)<<"] "
#define int long long

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 5e6 + 10;

using namespace std;

int n;
ll p,q,m,k;
ll res = 0;
int a[NMAX];

signed main() {
	fastio
	cin >> n;
	cin >> p >> q >> m;
	for (int i = 1;i<=n;i++) {
		a[i] = (p * i + q) % m;
	}
	cin >> k;
	int res = 0;
	for (int i = 1;i<=n;i++) {
		int maxx = a[i];
		int minn = a[i];
		for (int j = i;j<=n;j++) {
			maxx = max(maxx,a[j]);
			minn = min(minn,a[j]);
			if ((maxx - minn) <= k) res++;
		}
	}
	cout << res;
	
	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
