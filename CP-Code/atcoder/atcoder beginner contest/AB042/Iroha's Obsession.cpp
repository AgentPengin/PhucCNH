#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(val) "["#val" = "<<(val)<<"] "

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

map<int,int> mp;
int n,k;
int a[10001];

bool check(int n) {
	while(n != 0) {
		if (mp[n % 10]) return false;
		n/=10;
	}
	return true;
}

signed main() {
	fastio
	cin >> n >> k;
	for (int i = 1;i<=k;i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	int res = n;
	while(!check(res)) res++;
	cout << res;
	
	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
