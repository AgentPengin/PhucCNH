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
const int NMAX = 101;

int k[NMAX];
int h[1001];

int n,m;

bool order(int i,int j) {
    return (i >= j);
}

int main() {
    fastio
    cin >> n >> m;
    for (int i = 1;i<=n;i++) cin >> k[i];
    fill(h+1,h+n+1,0);
    sort(k+1,k+n+1,order);
    int dem = n,res = 0;
    while(dem > 0) {
        res++;
        int sum = 0;
        for (int j = 1;j<=n;j++) {
            if (h[j] == 0 && sum + k[j] <= m) {
                sum += k[j];
                h[j] = 1;
                dem--;
            }
        }
    }   
    cout << res;
    return 0;
}
// Code cua Phuc ;-;
