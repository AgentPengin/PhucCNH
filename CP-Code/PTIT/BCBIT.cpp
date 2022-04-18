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

using namespace std;

int dp[101][101][2];
int n,k;

int call(int pos,int cnt,int f) {
	if (pos == n) {
		if (cnt == k) return 1;
		else return 0;
	}
	if (dp[pos][cnt][f] != -1) return dp[pos][cnt][f];
	int res = 0;
	if (f == 1) {
		res += call(pos+1,cnt+1,1);
		res += call(pos+1,cnt,0);
	} else {
		res += call(pos+1,cnt,1);
		res += call(pos+1,cnt,0);
	}
	return dp[pos][cnt][f] = res;
}


signed main() {
	fastio
	int test;
	cin >> test;
	for (int _test = 1;_test <= test;_test++) {
		int x;
		cin >> x;
		cout << _test << " ";
		cin >> n >> k;
		memset(dp,-1,sizeof(dp));
		int res = call(0,0,0);
		cout << res << EL;
	}


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
