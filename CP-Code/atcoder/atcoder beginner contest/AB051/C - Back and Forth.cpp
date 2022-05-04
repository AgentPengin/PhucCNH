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

signed main() {
	fastio
	int sx,sy,tx,ty;
	cin >> sx >> sy >> tx >> ty;
	int dx = tx - sx;
	int dy = ty - sy;
	cout << string(dy,'U') << string(dx,'R');
	cout << string(dy,'D') << string(dx,'L');
	cout << 'L' << string(dy + 1,'U') << string(dx+1,'R') << 'D';
	cout << 'R' << string(dy+1,'D') << string(dx+1,'L') << 'U'; 
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
