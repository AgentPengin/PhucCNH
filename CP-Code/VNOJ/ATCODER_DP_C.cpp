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
const int N = 1e5 + 1;

int a[N],b[N],c[N];
int f[N][3];

void file() {
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
}

int main() {
    fastio
    //file();
    int n;
    cin >> n;
    int res = -1e9;
    for (int i = 1;i<=n;i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    f[1][1] = a[1];
    f[1][2] = b[1];
    f[1][3] = c[1];
    res = max({f[1][1],f[1][2],f[1][3]});
    for (int i = 2;i<=n;i++) {
        f[i][1] = max(a[i] + f[i-1][2],a[i] + f[i-1][3]);
        f[i][2] = max(b[i] + f[i-1][1],b[i] + f[i-1][3]);
        f[i][3] = max(c[i] + f[i-1][1],c[i] + f[i-1][2]);
        res = max({res,f[i][1],f[i][2],f[i][3]});
    }
    cout << res;


    return 0;
}
// Code cua Phuc ;-;
