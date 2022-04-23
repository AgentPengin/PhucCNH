#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

int n;
int a[22];

signed main() {
	fastio
	int test;
	cin >> test;
	while(test--) {
		cin >> n;
		for (int i = 1;i<=n;i++) cin >> a[i];
		int maxx = *max_element(a + 1,a+n+1);
		int minn = *min_element(a+1,a+n+1);
		cout << (maxx - minn) * 2 << EL;
	}


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
