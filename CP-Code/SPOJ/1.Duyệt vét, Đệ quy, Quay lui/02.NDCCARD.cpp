#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define DEBUG(x) do { std::cerr << #x << ": " << x; } while (0)

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

int a[10005];

signed main() {
	fastio
	int m,n;
	cin >> n >> m;
	for (int i = 1;i<=n;i++) cin >> a[i];
	pair<int,int> p[10005];
	for (int i = 1;i<=n-1;i++) {
		for (int j = i + 1;j<=n;j++) p[a[i] + a[j]] = {i,j};
	} 
	int32_t res = -inf;
	m = min(m,30000);
	for (int i = 1;i<=n;i++) {
		for (int j = m - a[i];j>=0;j--) {
			if (p[j] != pair<int,int>(0,0) && p[j].fi != i && p[j].se != i) res = max(res,a[i] + j); 
		}
	}
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
