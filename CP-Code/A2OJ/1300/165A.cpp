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

int n;
int x[1011],y[1011];

signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) {
		cin >> x[i] >> y[i];
	}
	int res = 0;
	for (int i = 1;i<=n;i++) {
		bool check_xup = false;
		bool check_xdown = false;
		bool check_yup = false;
		bool check_ydown = false;
		for (int j = 1;j<=n;j++) {
			if (x[i] == x[j] && y[i] > y[j]) check_ydown = true;
			if (x[i] == x[j] && y[i] < y[j]) check_yup = true;
			if (x[i] < x[j] && y[i] == y[j]) check_xup = true;
			if (x[i] > x[j] && y[i] == y[j]) check_xdown = true;	
		}
		if (check_ydown == true && check_yup == true && check_xdown == true && check_xup == true) {
			res++;
		}
	}
	cout << res;
	

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
