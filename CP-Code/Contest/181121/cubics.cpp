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
const int NMAX = 1e5+1;

int a[NMAX];
ll s[NMAX];


void file() {
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
}

int main() {
    fastio
    //file();
    int n,k;
    cin >> n >> k;
    s[0] = 0;
    map<int,int> mp;
    for (int i = 1;i<=n;i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i] - k;
    }
    int maxx = 0,id = 1;
    //for (int i = 1;i<=n;i++) cout << s[i] << " ";
    //cout << EL;
    for (int i = 1;i<=n;i++) {
        if (mp[s[i]] != 0) {
            if (maxx < i - mp[s[i]]) {
                maxx = i - mp[s[i]];
                id = mp[s[i]];
            }
        } else mp[s[i]] = i;
    }
    if (maxx == 0) {
        cout << "0";
        return 0;
    }
    cout << maxx << " " << id+1;
    return 0;
}
// Code cua Phuc ;-;
