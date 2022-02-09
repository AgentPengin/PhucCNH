#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)
#define int long long

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

signed main() {
	fastio
	int n = 50;
	int f[105];
	f[1] = 1;
	f[2] = 1;
	f[0] = 0;
	for (int i = 3;i<=n;i++) {
		f[i] = f[i-2] + f[i-1];
	}
	int ni;
	cin >> ni;
	for (int i = 0;i<=n;i++) {
		for (int j = 0;j<=n;j++) {
			for (int k = 0;k<=n;k++) {
				if (f[i] + f[j] + f[k] == ni) {
					cout << f[i] << " " << f[j] << " " << f[k];
					return 0;
				}
			}
		}
	}
	cout << "I'm too stupid to solve this problem";

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
