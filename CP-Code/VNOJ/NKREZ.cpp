#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define DEBUG(x) do { std::cerr << #x << ": " << x; } while (0)

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 1e4 + 10;

using namespace std;

pair<int,int> a[NMAX];
int f[NMAX];
int n;

bool cmp(pair<int,int> a,pair<int,int> b) {
	return a.se < b.se;
}
 
int search(int left,int right,int x) {
	int mid,res = 0;
	while(left <= right) {
		mid = (left + right)/2;
		if (a[mid].se <= x) {
			res = mid;
			left = mid + 1;
		} else right = mid - 1;
	}
	return res;
}
 
signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) {
		cin >> a[i].fi >> a[i].se;
	}
	sort(a+1,a+n+1,cmp);
	f[1] = a[1].se - a[1].fi;
	for (int i = 2;i<=n;i++) {
		int k = search(1,i-1,a[i].fi);
		f[i] = max(f[i-1],f[k] + a[i].se - a[i].fi);
	}
	cout << f[n];
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
