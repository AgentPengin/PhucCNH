// Problem: A. Perfect Permutation
// Contest: Codeforces - Codeforces Round #144 (Div. 2)
// URL: https://codeforces.com/problemset/problem/233/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

using namespace std;

bool cmp(int a,int b) {
	return a> b;
}

signed main() {
	fastio
	int n;
	cin >> n;
	if (n == 1) cout << -1,exit(0);
	int a[1001];
	for (int i = 1;i<=n;i++) {
		a[i] = i;
	}
	sort(a+1,a+n+1,cmp);
	if (n %2 != 0) cout << -1,exit(0);
	for (int i = 1;i<=n;i++) cout << a[i] << " ";
	


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
