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
	int n;
	cin >> n;
	pair<int,int> a[n+10];
	for (int i = 1;i<=n;i++) cin >> a[i].fi,a[i].se = i;
	sort(a+1,a+n+1);
	if (a[1].fi == a[2].fi) cout << "Still Rozdil";
	else cout << a[1].se;

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
