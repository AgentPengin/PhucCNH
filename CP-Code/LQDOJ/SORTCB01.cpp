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

int a[10005];

signed main() {
	fastio
	int n;
	cin >> n;
	for (int i = 1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = n;i>=1;i--) cout << a[i] << " ";


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
