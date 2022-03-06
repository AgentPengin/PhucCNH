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
const int NMAX = 1005;

using namespace std;

int m,n;
int a[NMAX][NMAX];
int f[NMAX],leftt[NMAX],rightt[NMAX];
deque<int> q;

void generateleftt() {
	q.clear();
	for (int j = 1;j<=n;j++) {
		while(!q.empty() && f[q.back()] >= f[j]) q.pop_back();
		if (q.empty()) leftt[j] = 1;
		else leftt[j] = q.back() + 1;
		q.push_back(j);	
	}
}

void generaterightt() {
	q.clear();
	for (int j = n;j>=1;j--) {
		while(!q.empty() && f[q.back()] >= f[j]) q.pop_back();
		if (q.empty()) rightt[j] = n;
		else rightt[j] = q.back() - 1;
		q.push_back(j);
	}
}

signed main() {
	fastio
	cin >> m >> n;
	for (int i = 1;i<=m;i++){
		for (int j = 1;j<=n;j++) cin >> a[i][j];
	}
	int res = -inf;
	for (int i = 1;i<=m;i++) {
		for (int j = 1;j<=n;j++) {
			if (a[i][j] == 0) f[j] = 0;
			else f[j] = f[j] + 1; 
		}
		generateleftt();
		generaterightt();
		
		for (int j = 1;j<=n;j++) {
			res = max(res,f[j] * (rightt[j] - leftt[j] + 1));
		}	
	}
	cout << res;
	

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
