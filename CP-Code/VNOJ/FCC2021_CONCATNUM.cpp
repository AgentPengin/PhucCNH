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
const int NMAX = 1e5 + 10;

using namespace std;

int len(int n) {
	int res = 0;
	while(n != 0) {
		res++;
		n /= 10;
	}
	return res;
}

int n,L,R,leftt,rightt;
int a[NMAX];
int power[18];


signed main() {
	fastio
	power[0] = 1;
	for (int i = 1;i<17;i++) {
		power[i] = power[i-1] * 10;
	}
	int test;
	cin >> test;
	while(test--) {
		cin >> n >> L >> R;
		int res = 0;
		for (int i = 1;i<=n;i++) cin >> a[i];
		sort(a+1,a+n+1);
		for (int i = 1;i<=n;i++) {
			int l = len(a[i]);
			if ((L - a[i])%(power[l]) == 0) leftt = (L - a[i])/(power[l]); 
			else leftt = (L - a[i])/(power[l]) + 1;
			rightt = (R - a[i])/(power[l]);
			if (leftt <= rightt) res += (upper_bound(a+1,a+n+1,rightt) - lower_bound(a+1,a+n+1,leftt));
		}
		cout << res << EL;
	}	

	



	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
