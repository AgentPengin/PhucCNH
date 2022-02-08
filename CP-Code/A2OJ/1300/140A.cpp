// Problem: B. Effective Approach
// Contest: Codeforces - Codeforces Round #140 (Div. 2)
// URL: https://codeforces.com/problemset/problem/227/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long

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
const int NMAX = 1e5 + 10;

using namespace std;

int n,m;
int a[NMAX];
map<int,int> mp;

signed main() {
	fastio
	int cnt1 = 0,cnt2 = 0;
	cin >> n;
	for (int i = 1;i<=n;i++) {
		cin >> a[i];
		mp[a[i]] = i;
	}
	cin >> m;
	for (int i = 1;i<=m;i++) {
		int x;
		cin >> x;
		cnt1 = cnt1 + mp[x];
		cnt2 = cnt2 + n - mp[x] + 1; 
	}
	cout << cnt1 << " " << cnt2;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
