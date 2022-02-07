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

// thay vi phai xay 1 cai parent[u] , height[u]
// height[u] = so luong bit trong bieu dien nhi phan cua u log2(u);
// parent[u] = u >> 1;


int64_t bit_count(int64_t u) {
	int64_t result = 0;
	while(u) {
		result++;
		u = u >> 1;
	}
	return result;
}

signed main() {
	fastio
	int32_t test;
	cin >> test;
	while(test--) {
		int64_t u,v;
		cin >> u >> v;
		int64_t height_u = bit_count(u);
		int64_t height_v = bit_count(v);
		if (height_u < height_v) swap(u,v),swap(height_u,height_v);
		while(height_u > height_v) u = u >> 1,height_u--;
		while(u != v) {
			u = u >> 1;
			v = v >> 1;
		}
		cout << u << EL;
	}	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
