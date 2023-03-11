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
map<int,vector<int>> mp;
map<int,int> dist;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    int test = 0;
    while(cin >> n,n) {
    	mp.clear();
    	for (int i = 1;i <= n;i++) {
    		int u,v;
    		cin >> u >> v;
    		mp[u].push_back(v);
    		mp[v].push_back(u);
    	}
    	int ru,d;
    	while(cin >> ru >> d && ru != 0 || d != 0) {
			test++;
    		dist.clear();
    		for (auto x : mp) {
    			dist[x.fi] = -1;
    		}
    		dist[ru] = 0;
    		queue<int> q;
    		q.push(ru);
    		while(!q.empty()) {
    			int u = q.front();
    			q.pop();
    			for (auto v : mp[u]) {
    				if (dist[v] == -1) {
    					dist[v] = dist[u] + 1;
    					q.push(v);
    				}
    			}
    		}
    		int cnt = 0;
    		for (auto x : mp) {
    			if (dist[x.fi] > d || dist[x.fi] == -1) {
    				cnt++;
    			}
    		}
    		cout << "Case " << test << ": " << cnt << " nodes not reachable from node " << ru << " with TTL = " << d << "."<< EL;
    	}
    	
    }
 	
    return 0;
}
// agent pengin wants to take apio (with anya-san)
