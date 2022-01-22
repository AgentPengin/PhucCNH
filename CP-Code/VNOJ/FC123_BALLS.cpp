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
const int NMAX = 2 * 1e5 + 10;

using namespace std;

int n;
int a[NMAX],cnt[NMAX];
signed main() {
	fastio
	cin >> n;
	map<int,int> mp;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int res = 0;
	for (int i = 1;i<=n;i++) {
		res += cnt[i] * (cnt[i]-1) / 2;
	}
	for (int i = 1;i<=n;i++) {
		cout << res - (cnt[a[i]] - 1) << EL;
	}
	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
