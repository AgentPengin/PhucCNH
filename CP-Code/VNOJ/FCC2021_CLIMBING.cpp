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
const int NMAX = 1e6 + 10;

using namespace std;

multiset<ll> karnie;
ll n,m,c;
vector<ll> res;
ll a[NMAX];

signed main() {
	fastio
	cin >> n >> m >> c; 
	for (int i = 1;i<=n;i++) {
		cin >> a[i];
		if (i < m) karnie.insert(a[i]);
	}
	karnie.insert(0);
	for (int i = m;i<=n;i++) {
		karnie.erase(karnie.find(a[i-m]));
		karnie.insert(a[i]);
		if (*karnie.rbegin() - *karnie.begin() <= c) res.push_back(i - m + 1);
	}
	if (res.empty()) cout << "NONE" << EL
	else {
		for (auto x : res) cout << x << " ";
	}

	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
