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

ll s,d;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    int test;
    cin >> test;
    while(test--) {
    	cin >> s >> d;
    	if ((s + d) % 2 != 0) {
    		cout << "impossible" << EL;
    		continue;
    	}
    	ll x = (s + d) / 2;
    	ll y = s - x;
    	if (x < 0 || y < 0) {
    		cout << "impossible" << EL;
    		continue;
    	}
    	cout << x << " " << y << EL;
    }
 	
    return 0;
}
// agent pengin wants to take apio (with anya-san)
