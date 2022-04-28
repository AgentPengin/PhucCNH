#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(val) "["#val" = "<<(val)<<"] "
#define int long long 

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 1e5 + 10;

using namespace std;

int m,n,k;
pair<int,int> p[NMAX];
map<pair<int,int>,int> mp;
int res[11];

signed main() {
	fastio
	cin >> m >> n >> k;
	for (int i = 0;i<k;i++) {
		cin >> p[i].fi >> p[i].se;
	}
	for(int i=0;i<k;i++){
		for(int px=p[i].fi-1;px<=p[i].fi+1;px++){
			for(int py=p[i].se-1;py<=p[i].se+1;py++){
				if(px<=1||py<=1||px>=m||py>=n)continue;
				mp[{px,py}]++;
			}
		}
	}
	res[0] = (m - 2) * (n - 2);
	for (auto x : mp) {
		res[x.se]++;
		res[0]--;
	}
	for (int i = 0;i<10;i++) cout << res[i] << EL;
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
