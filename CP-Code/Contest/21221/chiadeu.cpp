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
const double eps = 1e-10;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 1e3 + 10;

double a[NMAX];
map<double,int> mp;
map<double,int> mp2;

void file() {
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
}

bool BS(int l,int r,double x) {
        int mid;
        while(l <= r) {
            mid = (l+r)/2;
            if (abs(a[mid] - x) <= eps) return true;
            if (a[mid] > x) r = mid - 1;
            else l = mid + 1;
        }
        return false;
}


int main() {
    fastio
    //file();
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    ll res = 0;
    for (int i = 1;i<=n-1;i++) {
        for (int j = i + 1;j<=n;j++) {
            if (BS(i,j,(a[i]+a[j])/2)) res++;
        }
    }
    //for (auto x : mp) 
    cout << res;
    return 0;
}
// Code cua Phuc ;-;
