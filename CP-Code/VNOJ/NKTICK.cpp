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
const int NMAX = 60001;

using namespace std;

int32_t a[NMAX],t[NMAX],f[NMAX];

signed main() {
	fastio
	int n;
	cin >> n;
	for (int i = 1;i<=n;i++) cin >> a[i];
	for (int i = 2;i<=n;i++) cin >> t[i];
	f[1] = a[1];
	f[2] = min(t[2],f[1] + a[2]);
	for (int i = 3;i<=n;i++) {
		f[i] = min(f[i-1] + a[i],f[i-2] + t[i]);
	}
	cout << f[n];
	time;


	return 0;
}
// NNK <3
