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
const int NMAX = 1e5 + 10;

using namespace std;

int n,a[NMAX],k,res = 0;

bool cmp(int a,int b) {
	return a > b;
}

signed main() {
	fastio
	cin >> n >> k;
	for (int i = 1;i<=n;i++) cin >> a[i];
	sort(a+2,a+n+1,cmp);
	res = a[1];
	for (int i = 2;i<=n;i++) {
		if (k > 0) {
			res = res + a[i];
			k--;
		} else res = res - a[i];
	}
	cout << res;


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
