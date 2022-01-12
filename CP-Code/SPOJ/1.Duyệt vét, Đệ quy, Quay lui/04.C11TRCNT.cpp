#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define DEBUG(x) do { std::cerr << #x << ": " << x; } while (0)

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

pair<int,int> a[201];

bool check(int i,int j,int k) {
	int vector_x_ab = a[j].fi - a[i].fi;
	int vector_y_ab = a[j].se - a[i].se;
	int vector_x_ac = a[k].fi - a[i].fi;
	int vector_y_ac = a[k].se - a[i].se;
	return (ll)vector_x_ab * vector_y_ac != (ll)vector_x_ac * vector_y_ab;
}

int cnt[10001];

signed main() {
	fastio
	int n;
	cin >> n;
	int res = 0;
	for (int i = 1;i<=n;i++) cin >> a[i].fi >> a[i].se;
	for (int i = 1;i<=n;i++) {
		bool ok = false;
		for (int j = i + 1;j<= n;j++) {
			for (int k = j + 1;k<=n;k++) {
				if (check(i,j,k) == true) {
					res++;
					cnt[i]++;
					cnt[j]++;
					cnt[k]++;
				}
				//if (ok == true) break;
			}
		}
	}
	cout << res << EL;
	int id = 1;
	for (int i = 2;i<=n;i++) if (cnt[i] < cnt[id]) id = i;
	cout << id;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
