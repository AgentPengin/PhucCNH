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
const int N = 1e6 + 10;

using namespace std;

bool check[N];

void generate_prime_number() {
	memset(check,true,sizeof(check));
	check[1] = false;
	check[0] = false;
	for (int i = 2;i<=sqrt(N);i++) {
		if (check[i]) {
			for (int j = i * i;j<=N;j+=i) check[j] = false;
		}
	}
}
int a[N];
int s[N];
int f[N];
int p[N];

signed main() {
	fastio
	generate_prime_number();
	int n;
	cin >> n;
	s[0] = 0;
	for (int i = 1;i<=n;i++) {
		cin >> a[i];
		s[i] = s[i-1] + a[i];
		//cout << s[i] << " ";
	}
	p[2] = a[1];
	for (int i = 3;i<=n;i++) {
		if (check[i] == false) p[i] = p[i-1];
		else {
			p[i] = min(p[i-1],s[i] - a[i]);
		}
	}
	int res = -inf;
	for (int i = 3;i<=n;i++) {
		int tmp = inf;
		if (check[i]) {
			tmp = p[i-1];
		}
		res = max(res,s[i] - tmp); 
	}
	cout << res;
	
	
	//cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
