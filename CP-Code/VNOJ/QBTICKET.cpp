#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)
#define int long long

const int inf = 1e18 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 1e5 + 10;

int n,l[4],c[4],p[4],S,t;
int s[NMAX],f[NMAX];

using namespace std;

signed main() {
	fastio
	for (int i = 1;i<=3;i++) cin >> l[i];
	for (int i = 1;i<=3;i++) cin >> c[i];
	cin >> n >> S >> t;
	for (int i = 2;i<=n;i++) cin >> s[i];
	
	for (int i = 1;i<=3;i++) p[i] = S;
	
	for (int i = S+1;i<=t;i++) {
		f[i] = inf;
		for (int j = 3;j>=1;j--) {
			while(s[i] - s[p[j]] > l[j]) p[j]++;
			f[i] = min(f[i],f[p[j]] + c[j]);
			p[j-1] = p[j];
		}
	}
	cout << f[t];


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
