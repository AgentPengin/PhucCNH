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

int n,a,b;
int h[NMAX];

bool check(int x) {
	int sub = x * b;
	int cnt = 0;
	for (int i = 1;i<=n;i++) {
		if (h[i] > sub) {
			int tmp = h[i] - sub;
			//clog << db(tmp / a) << EL;
			if (tmp % (a-b) == 0) cnt += tmp/(a-b);
			else cnt += (tmp/(a-b) + 1);
		} 
 	}
 	if (cnt > x) return false;
 	else return true;
}

signed main() {
	fastio
	cin >> n >> a >> b;
	for (int i = 1;i<=n;i++) {
		cin >> h[i];
	}
	//cout << check(800000000) << EL;
	 int left = 1,right = 1e9,res;
	 while(left <= right) {
		 int mid = (left + right) >> 1;
		 if (check(mid)) {
			 res = mid;
			 right = mid - 1; 
		 } else left = mid + 1;
	 }
	 cout << res;
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
