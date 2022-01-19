#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)
#define int long long

const int inf = 1e18 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 1e6 + 10;

using namespace std;

int n,a,b;
pair<int,int> p[NMAX];
int sa[NMAX],sb[NMAX];

signed main() {
	fastio
	cin >> n >> a >> b;
	for (int i = 1;i<=n;i++) {
		cin >> p[i].fi >> p[i].se;
	}
	sort(p+1,p+n+1);
	sa[0] = 0;
	sb[0] = 0;
	for (int i = 1;i<=n;i++) {
		sa[i] = sa[i-1] + (p[i].se == 1);
		sb[i] = sb[i-1] + (p[i].se == 2);
	}
	
	int left = 1;
	int res = inf;
	for (int i = 1;i<=n;i++) {
		while(sa[i] - sa[left-1] >= a && sb[i] - sb[left-1] >= b) {
			res = min(res,p[i].fi - p[left].fi);
			left++;
		}
	}
	if (res == inf) cout << -1;
	else cout << res;
	


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
