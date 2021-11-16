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
const int NMAX = 1001;

int a[NMAX];

int main() {
	fastio
	int n;
	map<int,int> mp;
	int u;
	for (int i = 0;i<n;i++) {
		cin >> u;
		mp[u]++;
	}
	int tmp = 0;
	int res = 0;
	for (auto x : mp) {
		if (x.se >=4) tmp++;
		if (x.se >=2 ) res++;
	}
	cout << ((res)*(res-1))/2+tmp;

	return 0;
}
// Code cua Phuc ;-;
