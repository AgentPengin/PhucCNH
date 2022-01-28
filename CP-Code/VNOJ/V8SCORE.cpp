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

int s,k,n,sum = 0;
int a[21][21];
int x[21];

void xuat() {
	cout << "YES" << EL;
	for (int i = 1;i<=k;i++) cout << x[i] << " ";
	exit(0);
}

void backtrack(int i) {
	for (int j = 1;j<=n;j++) {
		if (a[j][i] >= x[i-1] && ((s - sum)/(k-i+1)) >= a[j][i]) {
			x[i] = a[j][i];
			sum = sum + x[i];
			if (i == k && sum == s) xuat();
			else backtrack(i+1);
			sum = sum - x[i];	
		} 
		
	}
	
}


signed main() {
	fastio
	cin >> s >> k >> n;
	for (int i = 1;i<=n;i++) {
		for (int j = 1;j<=k;j++) cin >> a[i][j];
	}
	memset(x,0,sizeof(x));
	backtrack(1);
	cout << "NO";
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
