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

ll cal(ll left,ll right,ll x) {
	if (right < x) return 0;
	while(right % x != 0 && right > left) right--;
	while(left % x != 0&& left < right) left++;
	if (left == right && left % x != 0) return 0;
	return (right - left)/x + 1;
	
}
ll l,r;

signed main() {
	fastio
	int test;
	cin >> test;
	while(test--) {
		cin >> l >> r;
		cout << cal(l,r,4) + cal(l,r,7) + cal(l,r,11) - cal(l,r,4*7) - cal(l,r,4*11) - cal(l,r,7 * 11) + cal(l,r,4*7*11) << EL;
	}


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
