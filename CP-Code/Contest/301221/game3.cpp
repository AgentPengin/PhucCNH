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

int n,m,b,f[1001][1001],a[1001][1001],s[1001][1001];

void file() {
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
}

int main() {
    fastio
    //file();
    cin >> n >> m >> b;
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) cin >> a[i][j];
    }
    memset(f,0,sizeof(f));
    memset(s,inf,sizeof(s));
    for (int j = 1;j<=m;j++) {
        f[1][j] = a[1][j] + b; 
        if (a[1][j] == 0) f[1][j] = b-b/2;

        s[1][j] = a[1][j] + b;
        if (a[1][j] == 0) s[1][j] = b-b/2; 
    }
    for (int i = 2;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            if (a[i][j] == 0) f[i][j] = max({f[i-1][j-1],f[i-1][j],f[i-1][j+1]})-max({f[i-1][j-1],f[i-1][j],f[i-1][j+1]})/2;
            else f[i][j] = max({f[i-1][j-1],f[i-1][j],f[i-1][j+1]}) + a[i][j];
            if (a[i][j] == 0) s[i][j] = min({s[i-1][j-1],s[i-1][j],s[i-1][j+1]})-min({s[i-1][j-1],s[i-1][j],s[i-1][j+1]})/2;
            else s[i][j] = min({s[i-1][j-1],s[i-1][j],s[i-1][j+1]}) + a[i][j];

            //cout << f[i][j] << " ";
        } 
    }
    int res = 0;
    int ans = 1e9;
    for (int i = 1;i<=m;i++) {
        res = max(f[n][i],res);
        ans = min(s[n][i],ans); 
    }
    cout << ans << EL << res;

    return 0;
}
// Code cua Phuc ;-;
