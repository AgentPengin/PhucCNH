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
const int NMAX = 1e5 + 1;

ll f[NMAX];
ll a[NMAX];

void file() {
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
}

int main() {
    fastio
    //file();
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++) cin >> a[i];
    if (n == 1) {
        cout << 0;
        return 0;
    }
    f[1] = 0;
    f[2] = abs(a[1] - a[2]);
    //cout << f[1] << " " << f[2] << EL;
    for (int i = 3;i<=n;i++) {
        f[i] = min(f[i - 2] + abs(a[i] - a[i-2]) ,abs(a[i] - a[i-1] )+f[i-1]); 
    }
    cout << f[n];
    return 0;
}
// Code cua Phuc ;-;
