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

int a[10001],n;
int s[10001];
vector<int> v;

void find_divide(int m) {
	for (int i = 1;i<=sqrt(m);i++) {
		if (m % i == 0) {
			if (i * i == m) v.push_back(i);
			else {
				v.push_back(i);
				v.push_back(m/i);
			}
		}
	}
}

signed main() {
	fastio
	int test,_test;
	cin >> test;
	while(test--) {
		cin >> _test >> n;
		for (int i = 1;i<=n;i++) cin >> a[i],s[i] = s[i-1] + a[i];
		find_divide(s[n]);
		sort(v.begin(),v.end());
		s[0] = 0;
		for (auto x : v) {
			int target = s[n] / x;
			int j = 1,cnt = 0;
			for (int i = 1;i<=n;i++) {
				if (s[i] - s[j - 1] == x) {
					j = i + 1;
					cnt++;	
				}
			}
			if (cnt == target) {
				cout << _test << " " << x << EL;
				break;
			}
		}
		v.clear();
	}

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
