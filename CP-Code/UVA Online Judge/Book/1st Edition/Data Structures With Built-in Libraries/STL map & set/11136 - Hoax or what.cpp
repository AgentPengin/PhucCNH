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

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
 	while(cin >> n,n) {
 		multiset<int> st;
 		ll cost = 0;
 		while(n--) {
 			int k;
 			cin >> k;
 			while(k--) {
 				int t;
 				cin >> t;
 				st.insert(t);
 			}
 			cost += *st.rbegin() - *st.begin();
 			st.erase(st.find(*st.rbegin()));
 			st.erase(st.find(*st.begin()));
 		}
 		cout << cost << EL;
 	}
    return 0;
}
// agent pengin wants to take apio (with anya-san)
