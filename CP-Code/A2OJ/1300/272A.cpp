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
const int NMAX = 105;

using namespace std;

int n;
int x,sum = 0;

signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) {
		cin >> x;
		sum += x;
	}
	int du = sum %(n+1);
	int res = 0;
	//db(sum);
	if ((du+1) %(n+1) != 1) res++;
	db(res);
	if ((du+2) %(n+1) != 1) res++;
	db(res);
	if ((du+3) %(n+1) != 1) res++;
	db(res);
	if ((du+4) %(n+1) != 1) res++;
	db(res);
	if ((du+5) %(n+1) != 1) res++;	
	cout << res;


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
