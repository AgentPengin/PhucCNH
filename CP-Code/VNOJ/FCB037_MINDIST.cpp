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
const int NMAX = 1e3 + 10;

using namespace std;

int a[NMAX],n;
map<int,int> mp;

signed main() {
	fastio
	cin >> n;
	bool check = false;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
		if (!mp[a[i]]) mp[a[i]]++;
		else check = true;
	}
	if (check == false)cout << -1 << EL
	else {
		int res = n;
		for (int i = 1;i<=n-1;i++) {
			for (int j = i + 1;j<=n;j++){
				if (a[i] == a[j]) res = min(res,abs( j - i));
			}
		}
		cout << res << EL;
	}
	


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
