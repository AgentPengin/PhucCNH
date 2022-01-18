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
const ll mod = 1e18;

using namespace std;

signed main() {
	fastio
	int test;
	cin >> test;
	ll a1,b1,a2,b2;
	while(test--) {
		cin >> a1;
		ll res1 = 1e8,res2 = 1e8;
		string s;
		if (a1 == 0) {
			res1 = a1;
			cin >> s;
		} else cin >> b1;
		cin >> a2;
		if (a2 == 0) {
			res2 = a2;
			cin >> s;
		} else cin >> b2;
		ll tmp = min(b1,b2);
		b1 -= tmp;
		b2 -= tmp;
		if (a1 == 0) res1 = a1;
		if (a2 == 0) res2 = a2;
		else {
			res1 = a1 * pow(10,b1);
			res2 = a2 * pow(10,b2);
		}
		if (res1 != res2) {
			cout << ((res1 < res2) ? "X < Y" : "X > Y") << EL;
		} else cout << "X = Y" << EL;
	}


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
