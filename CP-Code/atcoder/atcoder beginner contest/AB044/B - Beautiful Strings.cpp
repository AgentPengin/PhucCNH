#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(val) "["#val" = "<<(val)<<"] "

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

string s;
map<char,int> mp;

signed main() {
	fastio
	cin >> s;
	for (int i = 0;i<s.size();i++) {
		mp[s[i]]++;
	}
	for (auto x : mp) {
		if (x.se % 2 != 0) return cout << "No",0;
	}
	cout << "Yes";
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
