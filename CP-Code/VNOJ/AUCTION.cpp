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

int a[1001];

bool cmp(int a,int b) {
	return a > b;
}

signed main() {
	fastio
	int n,m;
	cin >> n >> m;
	for (int i = 1;i<=m;i++) cin >> a[i];
	sort(a+1,a+m+1,cmp);
	int res = -inf,ans;
	for (int i = 1;i<=min(m,n);i++) {
		if (a[i]*i > res) {
			res = a[i]*i;
			ans = a[i];
		}
	}
	cout << ans << " " << res << EL;
	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
