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

using namespace std;

signed main() {
	fastio
	int s1,s2,s3;
	map<int,int> mp;
	cin >> s1 >> s2 >> s3;
	for (int i = 1;i<=s1;i++) {
		for (int j = 1;j<=s2;j++) {
			for (int k = 1;k<=s3;k++) {
				mp[i+j+k]++;
			}
		}
	}
	int ans = 0,res = 0;
	for (auto x : mp) {
		if (ans < x.se) {
			ans = x.se;
			res = x.fi;
		}
	}
	cout << res;

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
