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
const int N = 1e7;

using namespace std;

bool check[N];
int sum[N],num[N];

void generate() {
	memset(check,true,sizeof(check));
	check[1] = false;
	check[0] = false; 
	for (int i = 2;i * i<=N;i++) {
		if (check[i]) for (int j = i * i;j<=N;j+=i) check[j] = false;
	}
	for (int i = 1;i<=N;i++) {
		if (check[i]) {
			num[i] = num[i-1] + 1;
			sum[i] = sum[i-1] + i; 
		} else{
			num[i] = num[i-1];
			sum[i] = sum[i-1];
		}
	}
}

signed main() {
	fastio
	generate();
	int test;
	sum[0] = 0;
	num[0] = 0;
	cin >> test;
	while(test--){
		int a,b;
		cin >> a >> b;
		double c = (double)(sum[b] - sum[a-1]);
		double d = (double)(num[b] - num[a-1]);
		cout << fixed << setprecision(2) << c/d << EL;
	}
	
 	

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
