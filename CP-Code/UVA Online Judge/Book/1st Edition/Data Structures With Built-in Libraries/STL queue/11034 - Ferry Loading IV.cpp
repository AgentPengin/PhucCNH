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

int carLength[N],l,m;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
	int test;
	cin >> test;
	while(test--) {
		cin >> l >> m;
		l *= 100;
		queue<int> q[2];
		for (int i = 1;i <= m;i++) {
			cin >> carLength[i];
			string s;
			cin >> s;
			if (s[0] == 'l') {
				q[0].push(carLength[i]); 
			} else {
				q[1].push(carLength[i]);
			}
		}
		int curTime = 0,sides = 0;
		while(!q[0].empty() || !q[1].empty()) {
			if (q[0].empty()) {
				if (sides == 0) {
					curTime++;
				} else {
					int totalLength = 0;
					while(!q[1].empty() && totalLength + q[1].front() <= l) {
						totalLength += q[1].front();
						q[1].pop();
					}
					curTime++;
				}
			} else if (q[1].empty()) {
				if (sides == 1) {
					curTime++;
				} else {
					int totalLength = 0;
					while(!q[0].empty() && totalLength + q[0].front() <= l) {
						totalLength += q[0].front();
						q[0].pop();
					}
					curTime++;
				}
			} else {
				int totalLength = 0;
				while(!q[sides].empty() && totalLength + q[sides].front() <= l) {
					totalLength += q[sides].front();
					q[sides].pop();
				}
				curTime++;
			}
			sides = 1 - sides;
		}
		cout << curTime;
		cout << EL;
	} 	
    return 0;
}
// agent pengin wants to take apio (with anya-san)
