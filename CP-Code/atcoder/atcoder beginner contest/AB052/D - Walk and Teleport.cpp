#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(val) "["#val" = "<<(val)<<"] "
#define int long long

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int N = 1e5 + 10;

using namespace std;

int a[N],n,_a,b;

signed main() {
	fastio
	cin >> n >> _a >> b;
	for (int i = 1;i<=n;i++) {
		cin >> a[i];
	}
	int res = 0;
	for (int i = 1;i<=n-1;i++) {
		if ((a[i + 1] - a[i])*_a > b) res += b;
		else res += (a[i+1] - a[i]) * _a;
	}
	cout << res;
	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
