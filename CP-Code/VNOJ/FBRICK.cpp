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

struct matrix{
	int x,y;
	ll a[5][5];
};

int A[5],n,m,F[5];
matrix a,x;

matrix operator *(matrix a,matrix b) {
	matrix c;
	c.x = a.x;
	c.y = b.y;
	for (int i = 1;i<=c.x;i++) 
		for (int j = 1;j<=c.y;j++) c.a[i][j] = 0LL;
	for (int i = 1;i<=c.x;i++) {
		for (int j = 1;j<=c.y;j++) {
			for (int k = 1;k<=a.y;k++) {
				c.a[i][j] = (c.a[i][j] + (ll)a.a[i][k]%m * (ll)b.a[k][j] % m) %m;
			}
		}
		
	}
	return c;
}

matrix powerMatrix(matrix a,int x) {
	if (x == 1) return a;
	matrix res = powerMatrix(a,x/2);
	if (x % 2) return res * res * a;
	else return res * res;
}

signed main() {
	fastio
	int test;
	cin >> test;
	while(test--) {
		cin >> A[2] >> n >> m;
		A[1] = F[1] = 1 % m;
		F[2] = (1LL + (ll)A[2] * A[2]) % m;
		if (n <= 2) {
			cout << F[n] << EL;
			continue;
		}		
		a.x = 4;
		a.y = 1;
		
		a.a[1][1] = (ll)F[2];
		a.a[2][1] = (ll)A[2] * A[2] % m;
		a.a[3][1] = 1LL % m;
		a.a[4][1] = (ll)A[2] % m;
		x.x = 4;
		x.y = 4;
		x.a[2][1] = x.a[3][1] = x.a[4][1] = x.a[3][3] = x.a[3][4] = x.a[4][3] = 0LL;
		x.a[1][1] = x.a[1][3] = x.a[2][3] = x.a[3][2] = 1LL % m;
		x.a[1][2] = x.a[2][2] = 4LL * (ll)A[2] * A[2] % m;
		x.a[1][4] = x.a[2][4] = -4LL * (ll)A[2] % m;
		x.a[4][2] = 2LL * (ll)A[2] % m;
		x.a[4][4] = -1LL;
		
		a = powerMatrix(x,n-2) * a; 
		ll res = (a.a[1][1] + (ll)m) % m;
		cout << res << EL;
	}

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
