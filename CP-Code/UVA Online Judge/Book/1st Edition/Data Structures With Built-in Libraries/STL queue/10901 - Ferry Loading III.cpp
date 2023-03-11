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

int n,t,m,carTime[10005],delion[10005];

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    int test;
    cin >> test;
    while(test--) {
    	cin >> n >> t >> m;
    	queue<int> q[2];
    	for (int i = 1;i <= m;i++) {
    		string s;
    		cin >> carTime[i] >> s;
    		if (s[0] == 'l') {
    			q[0].push(i);
    		} else {
    			q[1].push(i);
    		}
    	}
    	int sides = 0,curTime = 0;
    	while(!q[0].empty() || !q[1].empty()) {
    		if (q[0].empty()) {
    			if (curTime < carTime[q[1].front()]) {
    				curTime = carTime[q[1].front()];
    			}
    			if (sides == 0) {
    				curTime += t;
    			} else {
    				int nowdeCar = 0;
    				while(!q[1].empty() && carTime[q[1].front()] <= curTime && nowdeCar < n) {
    					nowdeCar++;
    					delion[q[1].front()] = curTime + t;
    					q[1].pop();
    				}
    				curTime += t;
    			}
    		} else if (q[1].empty()) {
    			if (curTime < carTime[q[0].front()]) {
    				curTime = carTime[q[0].front()];
    			}
    			if (sides == 1) {
    				curTime += t;
    			} else {
    				int nowdeCar = 0;
    				while(!q[0].empty() && carTime[q[0].front()] <= curTime && nowdeCar < n) {
    					nowdeCar++;
    					delion[q[0].front()] = curTime + t;
    					q[0].pop();
    				}
    				curTime += t;
    			}	
    		} else {
    			int nowdeCar = 0;
    			if (curTime < carTime[q[0].front()] && curTime < carTime[q[1].front()]) {
    				curTime = min(carTime[q[0].front()],carTime[q[1].front()]);
    			}
    			while(!q[sides].empty() && carTime[q[sides].front()] <= curTime && nowdeCar < n) {
    				nowdeCar++;
    				delion[q[sides].front()] = curTime + t;
    				q[sides].pop();
    			}	
    			curTime += t;
    		}
    		sides = 1 - sides;
    	}
    	for (int i = 1;i <= m;i++) cout << delion[i] << EL;
    	if (test) cout << EL;
    }
 	
    return 0;
}
// agent pengin wants to take apio (with anya-san)
