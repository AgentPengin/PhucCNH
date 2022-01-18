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
const int NMAX = 101;

using namespace std;

int n,u;
vector<pair<int,int>> a;

signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) {
		cin >> u;
		a.push_back({u,0});
	} 
	for (int i = 1;i<=n;i++) {
		cin >> u;
		a.push_back({u,1});
	}
	sort(a.begin(),a.end());
	int now = a[0].se;
	int res = 0;
	for (int i = 1;i<a.size();i++) {
		if (a[i].se + now == 1) {
			res++;
			now = -1;
		} else now = a[i].se;
	}
	cout << res;
	

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
