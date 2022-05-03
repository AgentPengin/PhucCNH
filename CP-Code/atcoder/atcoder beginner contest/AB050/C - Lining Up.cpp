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
const int NMAX = 1e5 + 10;
const int mod = 1e9 + 7;

using namespace std;

int n;
int a[NMAX];
unordered_map<int,int> mp;

int power(int n,int k) {
	if (k == 1) return n;
	if (k == 0) return 1LL;
	int tmp = power(n,k/2) % mod;
	if (k % 2 == 0) return (tmp * tmp) % mod;
	else return ((tmp * tmp) % mod * n % mod) % mod;
}

signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) cin >> a[i],mp[a[i]]++;
	// check false
	if (n % 2 != 0) {
		if (mp[0] > 1) return cout << 0,0;
		for (int i = 1;i<=n;i++) {
			if (a[i] % 2 != 0) return cout << 0,0; 
		}
	} else {
		if (mp[0]) return cout << 0,0;
		for (int i = 1;i<=n;i++) {
			if (a[i] % 2 == 0) return cout << 0,0;
		}
	}
	for (int i = 1;i<=n;i++) {
		if (mp[i] > 2) return cout << 0,0;
	}
	int res = 0;
	for (int i = 1;i<=n;i++) {
		if (mp[i] == 2) res++;
	}
	cout << power(2,res);
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
