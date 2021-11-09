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
	
int gcd(int a, int b) {
 	if (b == 0) return a;
 	return gcd(b, a%b);
}
int mods(string a,int b) {
	int mem = 0;
	for (int i = 0;i<a.size();i++) {
		mem = (mem*10 + a[i] - 48) % b;
	}
	return mem;
}
int main() {
	fastio
	int n;
	cin >> n;
	ll a[n+1];
	for (int i = 0;i<n;i++) cin >> a[i];
	ll tmp = abs(a[1]-a[0]);
	for (int i = 2;i<n;i++) {	
		tmp = gcd(abs(a[i]-a[i-1]),tmp);
	}
	cout << tmp;
	
	
	return 0;
}
// Code cua Phuc ;-;
