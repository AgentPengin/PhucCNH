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

int c,n;
int a[17];
int f[5000];

signed main() {
	fastio
	cin >> c >> n;
	for (int i = 1;i<=n;i++) {
		cin >> a[i];
		for (int j = c;j>=a[i];j--) {
			f[j] = max(f[j],f[j-a[i]] + a[i]);
		}
	}
	int res = 0;
	for (int i = 1;i<=c;i++) {
		res = max(res,f[i]);
	}
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
