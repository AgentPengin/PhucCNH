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
const int mod = 14062008;

using namespace std;

signed main() {
	fastio
	int n,k;
	cin >> n >> k;
	map<int,int> mp;
	for (int i = 1;i<=k;i++) {
		int u;
		cin >> u;
		mp[u]++;
	}
	int f[100001];
	f[0] = 1;
	if (!mp[1]) f[1] = 1;
	else f[1] = 0;
	if (!mp[2]) f[2] = 1;
	else f[2] = 0;  
	for (int i = 3;i<=n;i++) {
		if (mp[i]) f[i] = 0;
		else f[i] = (f[i-1]%mod + f[i-2]%mod) % mod;
	}
	cout << f[n];


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
