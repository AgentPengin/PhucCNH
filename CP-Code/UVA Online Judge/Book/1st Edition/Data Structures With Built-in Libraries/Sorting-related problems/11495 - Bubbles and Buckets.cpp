#include <bits/stdc++.h>

#define int long long
#define double long double
#define fi first
#define se second
#define EL '\n'

const int N = 1e5 + 5;
const int M = 1e3 + 5;
const int mod = 1e9 + 7;
const int inf = 1e18;

using namespace std;

int n,a[N],bit[N];

void update(int x,int val) {
	for (;x;x -= x & -x) bit[x] += val;
}

int getVal(int x) {
	int ans = 0;
	for (;x < N;x += x&-x) ans += bit[x];
	return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    if(ifstream("file.inp")){
    	freopen("file.inp", "r", stdin);
    	freopen("file.out", "w", stdout);
    }
  	while(cin >> n,n) {
  		memset(bit,0,sizeof bit);
  		for (int i = 1;i <= n;i++) cin >> a[i];
  		int ans = 0;
  		update(a[1],1);
  		for (int i = 2;i <= n;i++) {
  			int tmp = getVal(a[i] + 1);
  			ans += tmp;
  			update(a[i],1);
  		}
  		if (ans % 2 == 0) cout << "Carlos" << EL;
  		else cout << "Marcelo" << EL;
  	}
    return 0;
}
// special cooperative with tuntun
