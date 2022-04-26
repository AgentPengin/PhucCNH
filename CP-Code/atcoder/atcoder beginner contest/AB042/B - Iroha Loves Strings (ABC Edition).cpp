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

string s[101];
int n,l;

signed main() {
	fastio
	cin >> n >>  l;
	for (int i = 1;i<=n;i++) {
		cin >> s[i];
	}
	sort(s+1,s+n+1);
	for (int i = 1;i<=n;i++) cout << s[i];
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
