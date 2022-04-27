#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(val) "["#val" = "<<(val)<<"] "
#define int int64_t

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

string s;

signed main() {
	fastio
	cin >> s;
	int res = 0;
	for (int mask = 0;mask < (1 << (s.size() - 1));mask++) {
		string bin = "";
		for (int i = 0;i<(s.size() - 1);i++) {
			if (mask >> i & 1) bin = "1" + bin;
			else bin = "0" + bin;
		}
		string cur = "";
		cur = cur + s[0];
		bin = bin + "1";
		for (int i = 1;i<s.size() + 1;i++) {
			if (bin[i - 1] == '0') cur = cur + s[i];
			else {
				ll tmp = stoll(cur);
				res += tmp;
				cur = s[i];
			}
		}
	}
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
