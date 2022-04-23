#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 1e5 + 10;

using namespace std;

int n;
string s[NMAX];

signed main() {
	fastio
	int test;
	cin >> test;
	while(test--) {
		cin >> n;
		for (int i = 1;i<=n;i++) cin >> s[i];
		sort(s+1,s+n+1);
		bool flag = true;
		for (int i = 1;i<=n - 1;i++) {
			bool ok = true;
			for (int j = 0;j<s[i].size();j++) {
				if (s[i][j] != s[i+1][j]) ok = false; 
			}
			if (ok) flag = false;
		}
		if (flag) cout << "YES" << EL;
		else cout << "NO" << EL;
	}

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
