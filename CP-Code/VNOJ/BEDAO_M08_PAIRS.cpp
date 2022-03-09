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
const int NMAX = 1e7 + 10;

using namespace std;

ll m,n;
ll p[NMAX];
ll cnt[NMAX];

ll check(ll n) {
	if ((ll)sqrt(n) * (ll)sqrt(n) == n) return true;
	else return false;
}

void generate() {
	for (int i = 1; i <= n; i++) p[i] = i;
	
	for (int i = 2; i*i <= n; i++) {
	    for (int j = i*i; j <= n; j += i*i) p[j] = j / (i*i);
	}	
}

signed main() {
	fastio
	cin >> n >> m;
	generate();
	ll res = 0;
	for (int i = 1;i<=n;i++) {
		cnt[p[i]]++;		
	}
	ll left = 1,right = n;
	while(left < right) {
		if (left * right > m) {
			--cnt[p[right]];
			--right;
			continue;
		}
		res += (cnt[p[left]] - 1);
		cnt[p[left]]--;
		left++;
	}
	cout << res;


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
