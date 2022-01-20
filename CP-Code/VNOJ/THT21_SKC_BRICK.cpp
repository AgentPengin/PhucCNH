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
const int NMAX = 2e6 + 10;

using namespace std;

bool check[NMAX];
ll prime_number[NMAX];
ll next_gen[NMAX];
ll n,cnt = 0;

void generate() {
	memset(check,true,sizeof(check));
	check[0] = false;
	check[1] = false;
	for (int i = 2;i<=sqrt(NMAX);i++) {
		if (check[i] == true)
		for (int j = i*i;j<=NMAX;j+=i) check[j] = false;
 	}
 	for (int i = 2;i<=NMAX;i++) {
 		if (check[i]) prime_number[++cnt] = i;
 	}
	int dem = 0;
 	for (int i = 1;i<=cnt-1;i++) {
 		next_gen[i] = prime_number[i] * prime_number[i+1]; 
 	}
// 	for (int i = 1;i<=cnt;i++) {
 		//cout << next_gen[i] << EL;
// 	}
}


ll search(ll left,ll right,ll x) {
	ll res = 0,mid;
	while(left <= right) {
		mid = (left + right)/2;
		if (next_gen[mid] == x) return mid;
		else if (next_gen[mid] > x) right = mid - 1;
		else {
			res = mid;	
			left = mid + 1;
		}
	}
	return res;
}

void file() {
	freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
}

signed main() {
	fastio
	//file();
	generate();
	ll test;
	cin >> test;
	while(test--) {
		cin >> n;
		ll k = upper_bound(next_gen+1,next_gen+cnt+1,n) - next_gen;
		cout << n - next_gen[k-1] << EL;	
	}
	time;
	


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
