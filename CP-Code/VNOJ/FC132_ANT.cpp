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
	int64_t n,request,l,r;
	int64_t a[200001];
	cin >> n >> request;
	for (int i = 1;i<=n;i++) cin >> a[i];
	while(request--) {
		cin >> l >> r;
		if ((r - l + 1) %2 != 0) cout << 1 << EL
		else cout << a[l + (r - l + 1)/2] - a[l + (r - l + 1)/2 - 1] + 1 << EL;
		//cout << l << " " << r << EL; 
	}
	l = 1;
	r = 6;


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
