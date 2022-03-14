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

string a,b;

signed main() {
	fastio
	cin >> a;
	b = a;
	reverse(b.begin(),b.end());
	int m = a.size();
	int n = b.size();
	a = " " + a;
	b = " " + b;
	vector<vector<int>> f(m+1,vector<int>(n+1,0));
	
	for (int i = 1;i<=m;i++) {
		for (int j = 1;j<=n;j++) {
			if (a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
			else f[i][j] = max(f[i-1][j],f[i][j-1]);
		}
	}
	string res;
	while(f[m][n] > 0) {
		if (a[m] == b[n]) res += a[m],m--,n--;
		else if (f[m][n] == f[m-1][n]) m--;
		else n--;
	}
	cout << res;
	

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
