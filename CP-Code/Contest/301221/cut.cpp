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

int m,n,f[1001][1001];

void file() {
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
}

int main() {
    fastio
    //file();
    cin >> m >> n;
    f[1][1] = 1;
    f[2][2] = 1;
    f[3][3] = 1;
    for (int i = 2;i<=n;i++) {
        f[1][i] = i;
    }
    for (int j = 2;j<=m;j++) {
        f[j][1] = j;
    }
    for (int i = 1;i<=m;i++) {
        for (int j = 1;j<=n;j++) {
            if (i > j) f[i][j] = f[j][j] + f[i-j][j];
            else if (j > i) f[i][j] = f[i][i] + f[i][j-i];
            else f[i][j] = 1;
        }
    }
    cout << f[m][n];
    return 0;
}
// Code cua Phuc ;-;
