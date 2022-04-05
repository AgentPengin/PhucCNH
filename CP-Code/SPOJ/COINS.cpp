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

ll n;
unordered_map<ll,ll> mp;

ll dq(ll n) {
	if (n == 1) return 1;
	if (n == 0) return 0;
	if (n == 2) return 2;
	if (mp[n]) return mp[n];
	
	return mp[n] = max(n,dq(n/2) + dq(n/3) + dq(n/4)); 

}

signed main() {
	fastio
	while(cin >> n) {
		cout << dq(n) << EL;
	}

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
