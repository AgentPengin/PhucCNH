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

int a[1030][1030],f[1030][1030];

int getSum(int x,int y,int u,int v) {
	return f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1];
}

int d,n;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    int test;
    cin >> test;
    while(test--) {
    	for (int i = 1;i <= 1025;i++) {
    		for (int j = 1;j <= 1025;j++) {
    			f[i][j] = a[i][j] = 0;
    		}
    	}
    	cin >> d >> n;
    	for (int i = 1;i <= n;i++) {
    		int x,y,val;
    		cin >> x >> y >> val;
    		x++,y++;
    		a[x][y] += val;
    	}
    	for (int i = 1;i <= 1025;i++) {
    		for (int j = 1;j <= 1025;j++) {
    			f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
    		}
    	}
    	// d*= 2;
    	int ans = 0;
    	pair<int,int> id = {1,1};
    	for (int i = 1;i + d * 2 <= 1025;i++) {
    		for (int j = 1;j + d * 2 <= 1025;j++) {
    			if (ans < getSum(i,j,i + 2 * d,j + 2 * d)){
    				ans = getSum(i,j,i + 2 * d,j + 2 * d) ;
    				id = make_pair(i + d - 1,j + d - 1);
    			}
    		}
    	}	
    	// cout << id.fi - d + 1 << " " << id.se - d + 1 << EL;
    	cout << id.fi << " " << id.se << " " << ans << EL;
    }
 	
    return 0;
}
// agent pengin wants to take apio (with anya-san)
