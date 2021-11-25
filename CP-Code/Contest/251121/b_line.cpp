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
const int NMAX = 300;
const int N = 1e5+1;

int ct[N];
int a[NMAX][NMAX];
int m,n,k;

bool cmp(int a,int b) {
    return a > b;
}

int main() {
    fastio
    map<int,int> mp;
    cin >> m >> n >> k;
    for (int i = 0;i<m;i++) {
        for (int j = 0;j<n;j++) {
            cin >> a[i][j];
            ct[a[i][j]]++;
        }
    }   
    sort(ct,ct+N,cmp);
    ll res = 0;
    for (int i = 0;i<k;i++) res += ct[i];
    cout << res;
    return 0;
}
// Code cua Phuc ;-;
