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
const int NMAX = 4 * 1e5 + 10;

using namespace std;

ll a,b;

signed main() {
	fastio
	cin >> a >> b;
	ll res = a * b;
	if (res == 0) cout << 0;
	else if (res < 0) cout << -1;
	else if (res > 0) cout << 1;
	
	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
