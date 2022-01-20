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

int n;
int a[100001];
int s1[10001];
int s0[10001];

signed main() {
	fastio
	unordered_map<int,int> mp;
	cin >> n;
	for (int i = 1;i<=n;i++) cin >> a[i];
	int count0 = 0,count1 = 0;
	int res = 0;
	mp[0] = -1;
	for (int i = 1;i<=n;i++) {
		int u = a[i];
		if (u == 1) count1++;
		else count0++;
		int tmp = count1 - count0;
		if (mp[tmp] == -1) res = max(res,i-mp[tmp] - 1);
		else if (mp[tmp] != 0) res = max(res,i - mp[tmp]);
		else mp[tmp] = i;
	}
	cout << res;

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
