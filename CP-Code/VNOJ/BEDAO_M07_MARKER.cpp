#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)
#define int long long

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 1e6 + 5;

using namespace std;

int n,x;
int a[40];
int arr_1[NMAX];

signed main() {
	fastio
	cin >> n >> x;
	for (int i = 1;i<=n;i++) {
		cin >> a[i];
		a[i] -= x;
	}
	//for (int i = 1;i<=n;i++) cout << a[i] << " ";
	for (int mask = 0;mask < (1 << n/2);++mask) {
		for (int i = 1;i<=n/2;i++) {
			if ((mask >> (i-1)) & 1) {
				arr_1[mask] += a[i];
			}
		}
	}
	int n2 = (1 << (n/2));
	sort(arr_1,arr_1 + n2);
	int res = -1,sum;
	for (int mask = 0;mask < (1 << (n - n/2));mask++) {
		sum = 0;
		for (int i = 1;i<=(n - n/2);i++) {
			if ((mask >> (i-1)) & 1) {
				sum += a[i +n /2];
			}
		}
		res += (upper_bound(arr_1,arr_1 + n2,0 - sum) - lower_bound(arr_1,arr_1+n2,0 - sum));
	}
	cout << res;
	
	

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
