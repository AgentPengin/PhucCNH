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
const int NMAX = 5 * 1e5 + 10;

using namespace std;

int n;
map<string,ll> mp;
char c;

signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) {
		string s;
		cin >> s;
		if (mp[s]) {
			cout << "NO" << EL;
			cout << i;
			return 0;
		} 
		mp[s]++;
		if (i != 1) {
			if (s[0] != c) {
				cout << "NO" << EL;
				cout << i;
				return 0;
			}	
		}
		c = s[s.size()-1];
	}
	cout << "YES";

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
