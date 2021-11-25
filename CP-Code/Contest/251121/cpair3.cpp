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
const int NMAX = 1e6+1;

int main() {
    fastio
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    vi c(n);
    for (int i = 0;i<n;i++) cin >> a[i];
    for (int i = 0;i<n;i++) cin >> b[i];
    for (int i = 0;i<n;i++) cin >> c[i];    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    ll res = 0;
    for (int i = 0;i<n;i++) {
       ll x = lower_bound(a.begin(),a.end(),b[i]) - a.begin();
       ll y = upper_bound(c.begin(),c.end(),b[i]) - c.begin();
       res += x * (n-y);
    }
    cout << res;
    return 0;
}
// Code cua Phuc ;-;
