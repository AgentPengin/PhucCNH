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

int mx1,mx2,n,a[100007],t,s1,s2,res;

signed main() {
	fastio
	cin >> n >> t;
	for (int i = 1;i<=n;i++) cin >> a[i];
	for (int i = n;i>=1;i--) {
		mx1 = max(mx1,a[i]);
		s1 = max(s1,mx1 - a[i]);
	}
	for (int i = n;i>=1;i--) {
		mx2 = max(mx2,a[i]);
		if (mx2 - s1 == a[i]) res++;
	}
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
