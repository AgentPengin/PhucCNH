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
const int N = 1005;

int n,a[N];
stack<int> st;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    while(cin >> n) {
    	if (n == 0) break;
    	while(cin >> a[1],a[1]) {
	    	while(!st.empty()) st.pop();
		    for (int j = 2;j <= n;j++) cin >> a[j];
    		reverse(a + 1,a + n + 1);
    		int id = n;
    		for (int i = 1;i <= n;i++) {
    			if (a[i] == id) {
    				id--;
    				while(!st.empty() && st.top() == id) {
    					st.pop();
    					id--;
    				}
    			} else {
    				st.push(a[i]);
    			}
    		}
    		if (st.empty()) {
    			cout << "Yes" << EL;
    		} else {
    			cout << "No" << EL;
    		}
    	}
    	cout << EL;
    }
 	
    return 0;
}
// agent pengin wants to take apio (with anya-san)
