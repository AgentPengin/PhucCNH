/**
 *    author:  AgentPengin ( Độc cô cầu bại )
 *    created: 23.12.2022 10:08:02
 *    too lazy to update time
**/
#include<bits/stdc++.h>

#define fi first
#define se second
#define EL '\n'
#define NAME "DD"
#define db(x) cerr << #x << " == " << x << endl

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e6;

int n,cnt[105];

signed main() {             
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    while(cin >> n,n) {
    	for (int i = 1;i <= 100;i++) cnt[i] = 0;
    	for (int i = 1;i <= n;i++) {
    		int x;
    		cin >> x;
    		cnt[x]++;
    	}
    	string sep = "";
    	for (int i = 1;i <= 100;i++) {
    		++cnt[i];
    		while(--cnt[i]) {
    			cout << sep << i;
    			sep = " ";
    		}
    	}
    	cout << EL;
    }
    return 0;
}
// agent pengin wants to take apio (with anya-san)
