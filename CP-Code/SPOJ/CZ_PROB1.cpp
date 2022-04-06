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
const int N = 1e5;

using namespace std;

bool check[N + 10];
vector<int> prime;
int n,k;
int dp[5][10005];

void era() {
	memset(check,true,sizeof(check));
	check[0] = false;
	check[1] = false;
	for (int i = 2;i * i <= N;i++) {
		if (check[i]) for (int j = i * i;j <= N;j+=i) {
			check[j] = false;
		}
	}
}

void generate() {
	prime.push_back(-1);
	prime.push_back(2);
	for (int i = 3;i<=7994;i++) {
		if (i % 4 == 1 && check[i]){
			prime.push_back(i);
		}
	}
}

signed main() {
	fastio
	int test;
	era();
	generate();
	cin >> test;
	while(test--) {
		memset(dp,0,sizeof(dp));
		cin >> n >> k;
		int s = prime[n];
		dp[0][0] = 1;
		for (int i = 1;i<=k;i++) {
			for (int j = 0;j<=s;j++) {
				dp[i][j] = dp[i-1][j];
				if (j - i >= 0) {
					dp[i][j] = dp[i][j] + dp[i][j - i];
				}
			}
		}
		cout << dp[k][s] << EL;
	}

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
