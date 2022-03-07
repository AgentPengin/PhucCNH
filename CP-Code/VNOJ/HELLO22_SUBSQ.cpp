#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll unsigned long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

ll n;
ll powerTwo[65];

void generate() {
	powerTwo[0] = 1;
	for (int i = 1;i<=64;i++) {
		powerTwo[i] = powerTwo[i-1] * 2;
	}
}

signed main() {
	fastio
	ll test;
	cin >> test;
	generate();
	while(test--) {
		cin >> n;
		vector<ll> v;
		for (ll i = 0;i<64;i++) {
			if ((n >> i) & 1) v.push_back(i);
		}	
		cout << v.size() << EL;
		for (int i = 0;i<v.size();i++) {
			cout << powerTwo[v[i] - (i)] << " ";
		}
		cout << EL;
	}	

	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
