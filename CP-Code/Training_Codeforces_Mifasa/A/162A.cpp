// Problem: A. Colorful Stones (Simplified Edition)
// Contest: Codeforces - Codeforces Round #162 (Div. 2)
// URL: https://codeforces.com/contest/265/problem/A
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

signed main() {
	fastio
	string s,t;
	cin >> s;
	cin >> t;
	int res = 1;
	int i = 0,j = 0;
	while(i < s.size() && j < t.size()) {
		if (s[i] == t[j]) {
			res++;		
			i++;
			j++;
		} else {
			j++;		
		}
	}
	cout << res;


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
