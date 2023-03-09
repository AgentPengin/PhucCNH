/**
 *    author:  AgentPengin ( Độc cô cầu bại )
 *    created: 23.12.2022 10:08:02
 *    too lazy to update time
**/
#include<bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define EL '\n'
#define NAME "NAME"
#define db(x) cerr << #x << " == " << x << endl

using namespace std;

const ll inf = 1e9 + 7;
const int N = 1e5 + 5;

int n,a[N];

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
	int test;
	cin >> test;
	while(test--) {
		cin >> n;
		for (int i = 1;i <= n;i++) cin >> a[i];
		int ans = 0;
		for (int i = 1;i <= n;i++) {
			if (a[i] != i) {
				int j = i + 1;
				for (j;j <= n;j++) {
					if (a[j] == i) break;
				}
				for (j;j >= i + 1;j--) {
					ans++;
					swap(a[j],a[j - 1]);
				}
			}
			// cout << ans << EL;
		}
		cout << "Optimal train swapping takes " << ans << " swaps." << EL;
	} 	
    return 0;
}
// agent pengin wants to take apio (with anya-san)
