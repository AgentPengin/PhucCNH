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

int n;
double chr[N];

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
		memset(chr,0,sizeof chr);
		for (int i = 1;i <= n;i++) {
			char c;
			int val;
			cin >> c >> val;
			chr[c] = val;
		}
		int line;
		double ans = 0;
		cin >> line;
		cin.ignore();
		for (int i = 1;i <= line;i++) {
			string s;
			getline(cin,s);
			for (auto x : s) {
				ans += chr[x];
			}
		}
		cout << fixed << setprecision(2) << (double)1.0 * ans / 100 << "$"<< EL;
	} 	
    return 0;
}
// agent pengin wants to take apio (with anya-san)
