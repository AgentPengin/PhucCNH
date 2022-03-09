#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)
#define int long long

const ll inf = 1e18 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

ll m,n,q;
ll a[1005][10005];

ll sum(int x, int y, int u, int v) {
    return a[u][v] - a[x-1][v] - a[u][y-1] + a[x-1][y-1];
}

ll mincut(ll x,ll y,ll u,ll v) {
	ll res = 1LL << 60;
	ll full = sum(x,y,u,v);
	ll half = full/2;
	ll left = y,right = v;
	 while (left <= right) {
        int mid = (left + right) / 2;
        if (sum(x,y,u,mid) < half) left = mid + 1;
        else right = mid-1;
    }
	//res = min({res,abs(full - 2 * sum(x,y,u,left)),abs(full - 2 *sum(x,y,u,right))});
	 res = min(res, min(
                abs(full - 2*sum(x,y,u,left)),
                abs(full - 2*sum(x,y,u,right))
            ));
	left = x,right = u;
	 while (left<=right) {
        int mid = (left+right) / 2;
        if (sum(x,y,mid,v) < half) left = mid + 1;
        else right = mid - 1;
    }
	//res = min({res,abs(full - 2*sum(x,y,left,v)),abs(full - 2 * (x,y,right,v))});
	  res = min(res, min(
                abs(full - 2*sum(x,y,left,v)),
                abs(full - 2*sum(x,y,right,v))
            ));
	return res;
	
}

signed main() {
	fastio
	cin >> m >> n >> q;
	for (ll i = 1;i<=m;i++) {
		for (ll j = 1;j<=n;j++) {
			cin >> a[i][j];
			a[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];  
		}
	}
	while(q--) {
		ll x,y,u,v;
		cin >> x >> y >> u >> v;
		cout << mincut(x,y,u,v) << EL;
	}
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
