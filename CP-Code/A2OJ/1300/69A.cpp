// Problem: A. Panoramix's Prediction
// Contest: Codeforces - Codeforces Beta Round #69 (Div. 2 Only)
// URL: https://codeforces.com/problemset/problem/80/A
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

bool check_prime(int n) {
	if (n < 2) return false;
	else for (int i = 2;i<=sqrt(n);i++) if (n %i == 0) return false;
	return true;
}

signed main() {
	fastio
	int n,m;
	cin >> n >> m;
	int i = n+1;
	while(!check_prime(i)) i++;
	if (i == m) cout << "YES";
	else cout << "NO";


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
