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
const int NMAX = 5*1e6 + 10;

using namespace std;

ll f[NMAX];

signed main() {
	fastio
	string s;
	cin >> s;
	f[0] = 2;
	int j;
	for (int i = 1;i<s.size();i++) {
		bool check = true;
		for (j = i - 1;j>=0;j--) {
			if (s[i] == s[j]) {
				check = false;
				break;
			}
		}
		if (check == true) f[i] = f[i-1] + 2;
		else f[i] = min(f[j] + (i-j-1)*2 + 1,f[i-1]+2);
	}
	cout << f[s.size()-1];
	return 0;
}
// Code cua NKN ༼ つ ◕_◕ ༽つ
