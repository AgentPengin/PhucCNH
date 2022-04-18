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

int n;
int f[1001];

signed main() {
	fastio
	int test;
	cin >> test;
	f[1] = 1;
	f[0] = 1;
	f[2] = 2;
	for (int i = 3;i<=1000;i++) {
		f[i] = 0;
		if (i % 2 == 0) {
			for (int j = 0;j<=i;j+=2) {
				f[i] += f[(i - j)/2];
			}
		} else {
			for (int j = 1;j<=i;j+=2) {
				f[i] += f[(i - j)/2];
			}
		}
	}
	for (int _test = 1;_test<=test;_test++) {
		int x;
		cin >> x;
		cout << _test << " " << f[x] << EL;
	}

	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
