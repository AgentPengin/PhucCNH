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
const int NMAX = 5e5 + 5;

using namespace std;

int n,q,l,r;
string s;
char c;
int f[30][NMAX];
int request;

void update(int t,int u,int val) {
	while(u <= n) {
		f[t][u] += val;
		u += (u&-u);
	}
}

int getVal(int t,int u) {
	int res = 0;
	while(u > 0) {
		res += f[t][u];
		u -= (u&-u);
	}
	return res;
}

signed main() {
	fastio
	cin >> n;
	cin >> s;
	cin >> q;
	for (int i = 0;i<s.size();i++) update(s[i] - 'a',i+1,1);
	while(q--) {
		cin >> request;
		if (request == 1) {
			cin >> l >> c;
			update(s[l-1] - 'a',l,-1);
			s[l-1] = c;
			update(s[l-1] - 'a',l,1);
		} else {
			cin >> l >>  r;
			int res = 0;
			for (int i = 0;i<26;i++) res += (getVal(i,r) - getVal(i,l-1) > 0);
			cout << res << EL;
		}
		
	}


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
