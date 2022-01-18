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
const int NMAX = 1e6 + 5;

using namespace std;

int n,q,x,request;

signed main() {
	fastio
	cin >> n >> q;
	vector<vector<int>> f(NMAX,vector<int> (3,0));
	for (int i = 1;i<=n;i++) {
		cin >> x;
		for (int j = 1;j<=x;j++) {
			cin >> request;
			if (f[request][2] == i-1) f[request][1]++;
			else if (f[request][2] != i) f[request][1] = 1;
			f[request][0] = max(f[request][0],f[request][1]);
			f[request][2] = i;
		}
	}
	while(q--) {
		cin >> x;
		cout << f[x][0] << EL;
	}


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
