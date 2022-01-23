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

using namespace std;

int res = -1;

string s;
int cnt[10001];

bool check_prime_number(int n) {
	if (n < 2) return false;
	for (int i = 2;i<=sqrt(n);i++) if (n %i == 0) return false;
	return true;
}

void back_track(int u) {
	if (u == s.size()) {
		string curr = "";
		bool check = false;
		for (int i = 0;i<s.size();i++) {
			if (cnt[i] == 1) {
				curr = curr + s[i];
				check = true;	
			}
		}
		if (check == true) {
			ll n = stoi(curr);
			if (check_prime_number(n) == true) res = max(res,n); 
		}
		return;
	} 
	for (int i = 0;i<=1;i++) {
		cnt[u] = i;
		back_track(u+1);
	}
	
	
}


signed main() {
	fastio
	cin >> s;
	back_track(0);
	cout << res;	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
