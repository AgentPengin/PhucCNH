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

int n;
int a[101];

signed main() {
	fastio
	int test;
	cin >> test;
	while(test--) {
		cin >> n;
		bool check = false;
		for (int i = 1;i<=n;i++) cin >> a[i];
		
		for (int i = 1;i<=n-2;i++) {
			for (int j = i+1;j<=n-1;j++) {
				for (int k = j+1;k<=n;k++) {
					if (a[i] + a[j] == a[k] || a[j] + a[k] == a[i] || a[k] + a[i] == a[j]) {
						check = true;
						//cout << "YES" << EL;
						break;
					}
				}
				if (check == true) break;
			}	
			if (check == true) break;
		}
		
		if (check) cout << "YES" << EL
		else cout << "NO" << EL;
	}


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
