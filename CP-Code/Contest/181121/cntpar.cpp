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

void file() {
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
}

int main() {
    fastio
    //file();   
    int n;
    cin >> n;
    pii a[2005];
    map<pair<int,int>,int> mp;
    for (int i = 1;i<=n;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<i;j++) {
            mp[ {a[i].fi+a[j].fi,a[i].se+a[j].se} ]++;
            //cout << a[i].fi + a[j].fi << " " << a[i].se + a[j].se << EL;
        }
    }
    ll res = 0;
    //cout << mp[{3,1}] << EL;
    for (auto x : mp) {
       res += (x.se*(x.se-1))/2;
    }
    cout << res;
}
// Code cua Phuc ;-;
