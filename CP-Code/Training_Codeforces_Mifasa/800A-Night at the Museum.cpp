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
	string s;
	cin >> s;
	int res = 0;
	char now = s[0];
	res = res + min(abs(s[0] - 'a'),26 - abs(s[0] - 'a'));
	for (int i = 1;i<s.size();i++) {
		res += min(abs(s[i] - now),26 - abs(s[i] - now));
		now = s[i];
	}
	cout << res;

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
