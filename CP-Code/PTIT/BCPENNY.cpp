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

string s;
int n;

string init[101] = {"TTT","TTH","THT","THH","HTT","HTH","HHT","HHH"};

int cnt(string c) {
	int res = 0;
	for (int i = 0;i<s.size() - 2;i++) {
		if (s[i] == c[0] && s[i+1] == c[1] && s[i+2] == c[2]) res++;
 	}
	return res;
}

signed main() {
	fastio
	int test;
	cin >> test;
	while(test--) {
		cin >> n;
		cin >> s;
		cout << n << " ";
		for (int i = 0;i<8;i++) cout << cnt(init[i]) << " ";
		cout << EL;
	}
	


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
