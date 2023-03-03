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

double H,U,D,F;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
 	while(cin >> H >> U >> D >> F) {
 		if (H == 0 && U == 0 && D == 0 && F == 0) break;
 		int day = 0;
 		double increase = U,now = 0;
 		while(true) {
 			day++;
 			now += increase;
 			if (now > H) {
 				cout << "success on day " << day << EL; 
 				break;
 			}
 			now -= D;
 			if (now < 0) {
 				cout << "failure on day " << day << EL;
 				break;
 			}
 			increase = max(0.0,increase - U * F  / 100);
 		}
 	}
    return 0;
}
// agent pengin wants to take apio (with anya-san)

