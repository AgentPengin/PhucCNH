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

bool check(ll n) {
	if (n < 2) return false;
	if (n %2 == 0 && n != 2) return false;
	for (int i = 2;i<=sqrt(n);i++) if (n %i == 0) return false;
	return true;
}

signed main() {
	fastio
	cin >> n;
	for (int q = 2;q<=63;q++) {
		ll p = round(exp(log(n)/q));
		ll tmp = 1;
		for (int i = 1;i<=q;i++) tmp = tmp * p;
		if (tmp == n && check(p) == true) {
			cout << p << " " << q;
			return 0;
		}
	}
	cout << 0;


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
