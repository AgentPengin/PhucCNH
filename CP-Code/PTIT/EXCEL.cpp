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
	while(cin >> s) {
		if (s == "R0C0") return 0;
		int r = 0;
		string tmp = "";
		for (int i = 1;i<s.size();i++) {
			if (s[i] == 'C') {
				r = i;
				break;
			}
			else tmp = tmp + s[i];
		}
		string num = "";
		for (int i = r + 1;i<s.size();i++) {
			num = num + s[i];
		}		
		ll n = stoll(num);
		ll cur = 26;
		string res = "";
 
 
		while(n != 0) {
			if (n % cur == 0) {
				res = 'Z' + res;
				n -= cur;
			} else {
				ll du = n % cur;
				ll c = du / (cur / 26);
				res = char(c + 'A' - 1) + res;
				n -= c * (cur / 26);
			}
			cur *= 26;
		}
		cout << res << tmp << EL;
	}
 
	return 0;
}
// Code cua Phuc à¼¼ ã¤ â_â à¼½ã¤ 
 
