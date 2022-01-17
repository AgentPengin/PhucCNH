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
const int NMAX = 1e6 + 5;

using namespace std;

int n;
int a[NMAX];
int prefix[NMAX],suffix[NMAX];

signed main() {
	fastio
	cin >> n;
	if (n == 1) {
		cout << int(1e9);
		return 0;
	}
	for (int i = 1;i<=n;i++) cin >> a[i];
	prefix[1] = a[1];
	prefix[0] = 1;
	suffix[n+1] = 1;
	for (int i = 2;i<=n;i++) {
		prefix[i] = __gcd(prefix[i-1],a[i]);
	}
	suffix[n] = a[n];
	for (int i = n - 1;i>=1;i--) {
		suffix[i] = __gcd(suffix[i+1],a[i]);
	}
	int res = max(prefix[n-1],suffix[2]);
	for (int i = 2;i<=n-1;i++) {
		res = max(res,__gcd(suffix[i+1],prefix[i-1]));
	}
	cout << res;

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
