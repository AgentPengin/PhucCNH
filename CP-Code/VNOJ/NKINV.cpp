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
const int N = 60005;

using namespace std;

int n,bit[N],x;
ll res = 0;

int retrieve(int x) {
	int ans = 0;
	for (; x < N;x += x&-x) ans += bit[x];
	return ans;
}

void update(int x) {
	for (;x > 0;x -= x&-x) bit[x]++;
}


signed main() {
	fastio
	cin >> n;
	while(n--) {
		cin >> x;
		res += retrieve(x+1);
		update(x);
	}
	cout << res;
	
	
	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
