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
const int N = 1e6 + 10;

using namespace std;
int n;
bool check[N];
map<ll,ll> Prime;

void sieve(int N) {
	for (int i = 1;i<=N;i++) {
		int num = i;
		while(num % 2 == 0) {
			Prime[2]++;
			num /= 2;
		}
		for (int j = 3;j * j <= num;j+=2) {
			while(num % j == 0) {
				Prime[j]++;
				num/=j;
			}
		}
		if (num != 1) {
			Prime[num]++;
		}
	}
}

signed main() {
	fastio
	cin >> n;
	sieve(n);
	ll res = 1;
	for (auto x : Prime) {
		res = (res * (x.se + 1)) % inf; 
	}
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
