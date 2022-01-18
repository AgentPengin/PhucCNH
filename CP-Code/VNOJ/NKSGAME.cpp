#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)
#define int long long

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 1e5 + 10;


using namespace std;

int a[NMAX],b[NMAX],n;

int search(int left,int right,int x) {
	int mid,res = inf;
	while(left <= right) {
		mid = (left + right)/2;
		if (abs(b[mid]+x) < res) {
			res = abs(b[mid] + x);
		} 
	}
}

signed main() {
	fastio
	cin >> n;
	for (int i = 0;i<n;i++) cin >> a[i];
	for (int i = 0;i<n;i++) cin >> b[i];
	sort(a,a+n);
	int res = abs(a[0] + b[0]);
	for (int i = 0;i<n;i++) {
		int id = lower_bound(a,a+n,-b[i]) - a;
 		if (0 <= id && id < n && abs(a[id] + b[i]) < res) res = abs(a[id] + b[i]);
 		if (0 <= id-1 && id < n+ 1 && abs(a[id-1] + b[i]) < res) res = abs(a[id-1] + b[i]);
 	}
 	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
