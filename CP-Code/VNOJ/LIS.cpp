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
	vector<int> a(n);
	for (int &x : a) cin >> x;
	int res = -inf;
	
	vector<int> f(n+1),b(n+1,INT_MAX);
	b[0] = INT_MIN;
	for (int x : a) {
		int k = lower_bound(b.begin(),b.end(),x) - b.begin();
		b[k] = x;
		res = max(res,k);
	}
	cout << res;

	return 0;
}
// Nguyen Kha Nhien <3
