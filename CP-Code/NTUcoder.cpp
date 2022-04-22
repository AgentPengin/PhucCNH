#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

signed main() {
	fastio
	ll n;
	cin >> n;
	ll day = n / 7;
	if (day % 2 == 0) {
		ll left = 7 - n % 7;
		ll right = 7 - left;
		cout << left << " " << right;
	} else {
		ll left = 7 - n % 7;
		ll right = 7 - left;
		swap(left,right);
		cout << left << " " << right;
	}


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
