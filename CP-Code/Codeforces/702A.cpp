#include<iostream>
#include<iomanip>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<vector>
#include<utility>
#include<set>
#include<queue>

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

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 51;

int n;
int a[NMAX];

bool check(int a,int b) {
	if (a == b) return true;
	else {
		if (max(a,b)%min(a,b) == 0) {	
			if (max(a,b)/min(a,b) - 2 < eps ) return true;
			else return false;
		} else {
			if (max(a,b)/min(a,b) -1 < eps) return true;
			else return false;
		}
	}
}

int main() {
	fastio
	int t;
	cin >> t;
	int x,y;
	while (t--) {
		cin >> n;
		int res = 0;
		for (int i = 0;i<n;i++) cin >> a[i];
		
		for (int i = 0;i<n-1;i++) {
			if (check(a[i],a[i+1]) == false) {
				x = max(a[i],a[i+1]);
				y = min(a[i],a[i+1]);	
				while (check(x,y) == false) {
					if (x %2 == 0) x = x/2;
					else x = x/2+1;
					res++;
				}
			}
		}
		cout << res << EL;
	}
	return 0;
}
// Code cua Phuc ;-;
