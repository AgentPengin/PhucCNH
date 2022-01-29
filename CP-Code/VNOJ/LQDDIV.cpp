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
const int N = 500001;

using namespace std;
int n;
int sum,a[N],x[N],m,s,res,cnt;

void browse(int i) {
	if (i == n/2+1) {
		x[++m] = s;
		return;
	}
	browse(i+1);
	s += a[i];
	browse(i+1);
	s -= a[i];
}

void process() {
	int target = sum - 2*s, good = sum+5, cntt = 0;
	
	int left = 1, right = m, mid, pos = 0;
	
	while (left <= right) {
		mid = (left + right)/2;
		if (2 * x[mid] <= target) {
			pos = mid;
			left = mid+1;
		} else right = mid-1;
	}
	if (pos > 0) good = abs(target-2*x[pos]);
	if (abs(target - 2*x[pos+1]) < good) good = abs(target - 2*x[++pos]);

	if (good == sum+5 or (res < sum+5 and good > res)) return ;

	int L = pos-1, R = pos+1;
	cntt = 1;
	while (L > 0 and good == abs(target - 2*x[L])) {
		L--;
		cntt++;
	}
	while (R <= m and good == abs(target - 2*x[R])) {
		R++;
		cntt++;
	}
	if (res > good) {
		res = good;
		cnt = cntt;
	} else cnt += cntt;
}

void browse_2(int i) {
	if (i == n+1) {
		process();
		return ;
	}
	browse_2(i+1);
	s += a[i];
	browse_2(i+1);
	s -= a[i];
}


signed main() {
	fastio
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	res = sum+5;
	
	browse(1);
	sort(x+1,x+m+1);
	s = 0;
	browse_2(n/2+1);

	cout << res << " " << cnt/2;

	return 0;
}
