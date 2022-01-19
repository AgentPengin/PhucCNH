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
const int NMAX = 3000000;

using namespace std;

ll n,k,d;
bool is_prime[NMAX];
vector<int> prime;

void generate() {
	memset(is_prime,true,sizeof(is_prime));
	is_prime[0] = false;
	is_prime[1] = false;
	for (int i = 2;i*i<NMAX;i++) {
		if (is_prime[i]) {
			for (int j = i*i;j<NMAX;j+=i) is_prime[j] = false;
		}
	}
	for (int i = 0;i<NMAX;i++) if (is_prime[i]) prime.push_back(i);
	d = prime.size();
}

void solve() {
	ll res = 0;
	for (int i = 0;i<d-k+1;i++) {
		ll s = 1;
		for (int j = i;j<i+k;j++) {
			s = s * prime[j];
		}
		if (s > n) break;
		else res = max(res,s);
	}
	if (res !=0 ) cout << res << EL
	else cout << -1 << EL;
}

signed main() {
	fastio
	//cin >> n >> k;
	int test;
	cin >> test;
	generate();
	while(test--) {
		cin >> n >> k;
		solve();
	}


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
