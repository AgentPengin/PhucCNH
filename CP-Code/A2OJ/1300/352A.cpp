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
	int n,t,f(0),z(0);
	cin >> n;
	for (int i = 0;i<n;i++) {
		cin >> t;
		if (t == 0) {
			z++;
		} else if (t==5) f++;
	}
	if (z==0) cout << -1;
	else if (f < 9) cout << 0 << EL
	else {
		f -= f %9;
		for (int i = 0;i<f;i++) cout << 5;
		for (int i = 0;i<z;i++) cout << 0;
		
		
	}

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
