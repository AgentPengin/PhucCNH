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
    
unordered_map<ll,ll> mp;

void file() {
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
}

void generate() {
    ll tmp;
    for (ll i = 2;i<=1e6;i++) {
        tmp = i * i * i;
            while(true) {
                if(!mp[tmp]) mp[tmp] = i;
                if (tmp > 1e18/i) break;
                tmp *= i;
            } 
    }
}

signed main() {
    fastio
    file();
    generate();
    ll ans;
    int t;
    ll n;
    cin >> t;

    while(t--) {
        cin >> n;
        ll res = n;
        if (mp[n] != 0) res = mp[n];
        else {
           ans = sqrt(n);
           if (ans* ans == n) res = ans;
        }
        cout << res << EL;
    }
    return 0;
}
// Code cua Phuc ;-;
