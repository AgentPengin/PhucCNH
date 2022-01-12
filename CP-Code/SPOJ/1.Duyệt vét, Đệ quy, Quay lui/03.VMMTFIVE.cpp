#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define DEBUG(x) do { std::cerr << #x << ": " << x; } while (0)

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

int32_t d[6],c[6],a[6][6];

void output() {
	for (int i = 1;i<=5;i++) {
		for (int j = 1;j<=5;j++) cout << a[i][j] << " ";
		cout << EL;
	}
	exit(0);
}

void recursion(int i,int j) {
	if (i == 6) {
		if (c[5] == 0) output();
		return;
	}
	int left = max(1,max(d[i] - 25*(5 - j),c[j] - 25*(5-i)));
	int right = min(25,min(d[i] - 5 + j,c[j] - 5 + i));
	if (left > 25 || right < 1 || left > right) return;
	for (int x = left;x<=right;x++) {
		a[i][j] = x;
		d[i] -= x;
		c[j] -= x;
		if (j < 5) recursion(i,j+1);
		else recursion(i+1,1);
		d[i] += x;
		c[j] += x;
		a[i][j] = 0;
	}
}

signed main() {
	fastio
	for (int i = 1;i<=5;i++) cin >> d[i];
	for (int i = 1;i<=5;i++) cin >> c[i];
	recursion(1,1);
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
