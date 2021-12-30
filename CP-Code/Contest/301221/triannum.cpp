#include<iostream>
#include<iomanip>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<vector>
#include<utility>
#include<set>
#include<queue>
#include <chrono>
#include<map>

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> bigNum;
typedef  vector<vector<int>> vii;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
#define fi first
#define se second 
#define pb push_back
#define EL "\n"
#define FOR(i,a,b) for (int i = a;i<=b;i++) 
#define DEC(i,a,b) for (int i = a;i>=b;i--)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b))*b
#define time_start() auto start = chrono::steady_clock::now(); 
#define time_end() auto end = chrono::steady_clock::now();
#define time_use() cout << EL << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 105;

int x,n,f[NMAX][NMAX],a[NMAX][NMAX],res = -1e9;


void import() {
    memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    cin >> n;
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=i;j++) {
            cin >> x;
            a[i][j] = x;
        }
    }
}

void solve() {
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=i;j++) {
            f[i][j] = max(f[i-1][j],f[i-1][j-1]) + a[i][j];
            //cout << f[i][j] << " ";
        }
    }
    for (int i = 1;i<=n;i++) {
        res = max(res,f[n][i]);
    }
    cout << res;
}

int main() {
    fastio
    //file();
    import();
    solve();
    return 0;
}
// Code cua Phuc ;-;
