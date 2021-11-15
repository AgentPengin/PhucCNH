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
const int MAXN = 100001;

ll a[MAXN];
ll f[MAXN];


int main() {
	fastio
	ll n;
	cin >> n;
	map<ll,ll> d;
	f[0] = 0;
	for (int i = 1;i<=n;i++) {
		cin >> a[i];
		f[i] = f[i-1] + a[i];
	}
	ll s = 0;
	ll res = -1e18;
	for (int i = 1;i<=n;i++) {
		if (d.count(a[i])) {
			res = max(res,f[i] - d[a[i]]);
			d[a[i]] = min(f[i-1],d[a[i]]);
		} else d[a[i]] = f[i-1];
	}
	cout << res;
	return 0;
}
// Code cua Phuc ;-;
