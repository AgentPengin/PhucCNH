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

int a[4];

signed main() {
	fastio
	cin >> a[1] >> a[2] >> a[3];
	sort(a+1,a+3+1);
	if (a[1] == 5 && a[2] == 5 && a[3] == 7) return cout << "YES",0;
	else cout << "NO";
	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
