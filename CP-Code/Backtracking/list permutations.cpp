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
const int N = 1001;

int n;
int a[N],check[N];

void printX() {
	for (int i = 1;i<=n;i++) cout << a[i];
	cout << EL;
}
void backtracking(int k) {
	if (k > n) {
		printX();
		return;		
	}
	for (int i = 1;i<=n;i++) {
		if (check[i] == 0) {
			a[k] = i;
			check[i] = 1;
			backtracking(k+1);
			check[i] = 0;
		}
 	}
}
int main() {
	fastio
	cin >> n;
	backtracking(1);
 	
	return 0;
}
// Code cua Phuc ;-;
