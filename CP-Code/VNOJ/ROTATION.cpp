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
const int NMAX = 1e6 + 10;

using namespace std;

struct curoa{
	int s,d,c;
};

int n;
curoa a[NMAX];
int f[NMAX];

bool cmp(curoa a,curoa b) {
	return a.s < b.s;
}

signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n-1;i++) {
		cin >> a[i].s >> a[i].d >> a[i].c;
	}
	sort(a+1,a+n,cmp);
	f[1] = 0;
	for (int i = 1;i<=n-1;i++) {
		//cout << a[i].s << " " << a[i].d << " " << a[i].c << EL;
	}
	for (int i = 1;i<=n-1;i++) {
		if (a[i].c == 0) f[a[i].d] = f[a[i].s];
		else f[a[i].d] = 1 - f[a[i].s];
	}
	cout << f[n];
	
	


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
