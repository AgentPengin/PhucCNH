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

signed main() {
	fastio
	int n, x, y; cin >> n >> x >> y;
	int s1, s2, t1, t2; cin >> s1 >> s2 >> t1 >> t2;

	auto cal = [&](int a, int b, int c, int d) -> int {
		int tmp = min(abs(a - c) + abs(b - d), abs(a - d) + abs(b - c));
		return tmp * x;
	};
	int ans = 1e9;
	for (int d = -n; d <= n; d++) {
		int a = s1 + d, b = s2 + d;
		if (1 <= a && a <= n && 1 <= b && b <= n)
			ans = min(ans, y * abs(d) + cal(a, b, t1, t2));
	}
	cout << ans << '\n';
}
