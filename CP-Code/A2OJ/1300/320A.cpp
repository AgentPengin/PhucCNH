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

signed main() {
	fastio
	string s;
	cin >> s;
	int i = 0;
	//if (i )
	if (s[i] != '1') cout << "NO",exit(0);
	for (int i = 0;i<s.size();i++) {
		if (s[i] != '4' && s[i] != '1') cout << "NO",exit(0);
	}
	while(i < s.size()) {
		if (s[i] == '1') {
			if (s[i+1] == '4') {
				if (s[i + 2] == '4') i += 3;
				else i += 2;
			} else i += 1;
		} else cout << "NO",exit(0);
	}
	cout << "YES";
	


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
