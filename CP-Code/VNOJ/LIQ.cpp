#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL; } while (0)

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

int n;
int a[1001],f[1001];

signed main() {
	fastio
	cin >> n;
	int res = 1;
	for (int i = 1;i<=n;i++) {
		cin >> a[i];
		f[i] = 1;
		for (int j = 1;j<i;j++) {
			if (f[j] + 1 > f[i] && a[i] > a[j]) f[i] = f[j] + 1;
		}
		res = max(res,f[i]);
	}
	cout << res;
	time;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
