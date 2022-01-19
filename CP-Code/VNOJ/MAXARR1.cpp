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
const int N = 100000;

void file() {
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
}

ll s[N+5];
ll f[N+5];

void generate() {
    f[0] = 0;
    f[1] = 1;
    s[0] = 0;
    s[1] = 1;
    for (int i = 2;i<=N;i++) {
        if (i %2 == 0) f[i] = f[i / 2];
        else f[i] = f[(i-1)/2] + f[(i+1)/2];
        s[i] = max(s[i-1],f[i]); 
    }
}

int main() {
    fastio
    //file();
    int t;
    ll n;
    cin >> t;
    generate();
    while (t--) {
        cin >> n;
        cout << s[n] << EL;
    }
    return 0;
}
// Code cua Phuc ;-;
