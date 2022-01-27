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
const int NMAX = 1e6;

using namespace std;

int n,dem = 0,minn = inf;
string a[NMAX];

signed main() {
	fastio
	cin >> n;
	string tmp = "";
	for (int i = 0;i<n;i++) {
		char c;
		cin >> c;
		if (c != '#') {
			tmp = tmp + c;
		} else {
			a[++dem] = tmp;
			int siz = tmp.size();
			minn = min(minn,siz * 7);
			tmp = "";
		}
	}	
		a[++dem] = tmp;
		int siz = tmp.size();
			minn = min(minn,siz * 7);
		cout << dem << " " << minn << EL;
		double bit_1 = 0,bit_2 = 0;
		for (int i = 1;i<=dem;i++) {
			string s = a[i];
			for (int j = 0;j<minn / 7;j++) {
				bit_1 += __builtin_popcount(int(s[j]));
			}
		}
		bit_2 = dem * minn - bit_1;
		cout << fixed << setprecision(9) << double(bit_1/bit_2);
  
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
