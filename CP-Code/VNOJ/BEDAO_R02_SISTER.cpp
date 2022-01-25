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


bool check_prime(int n) {
	if (n < 2) return false;
	else for (int i = 2;i<=sqrt(n);i++) if (n %i == 0) return false;
	return true;
}

int n,res = -1; 
int c[21];
int x[21];

void analyze() {
	int tmp1 = 0;
	int tmp2 = 0;
	for (int i = 1;i<=n;i++) {
		if (x[i] == 1) tmp1 += c[i];
		else tmp2 += c[i];
	}
	if (check_prime(abs(tmp1-tmp2)) == true) res = max(res,tmp1 - tmp2);
}

void duyet(int u) {
	if (u == n + 1) {
		analyze();
		return;
	}
	for (int i = 0;i<=1;i++) {
		x[u] = i;
		duyet(u+1);
	}
}


signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) cin >> c[i];
	duyet(1);
	cout << res;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
