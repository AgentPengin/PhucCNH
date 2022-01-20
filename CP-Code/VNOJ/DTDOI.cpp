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
const int N = 1000000;

int n,s,a[150],f[N+5],res;

using namespace std;

signed main() {
	fastio
	cin >> n >> s;
	for (int i = 1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1;i<=N/n;i++) {
		f[i] = inf;
		for (int j = 1;j<=n;j++) {
			if (a[j] <= i) f[i] = min(f[i],f[i - a[j]] + 1);
			else break;
		}
	}
	if (s <= N/n) {
		cout << f[s];
		return 0;
	}
	int timer = 0;
	res = inf;
	for (int cnt = s/a[n];cnt>=1;cnt--) {
		int tmp = s - cnt * a[n];
		if (tmp > N/n || timer > N) break;
		res = min(res,cnt + f[tmp]);
		timer++;
	}
	cout << res;

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
