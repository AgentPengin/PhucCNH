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
#define debug "#:            "

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 100005;
string n;
int mod3,num[NMAX],x[3];

int main() {
	fastio
	cin >> n;
	int m = n.size(),ans = 0;
	for (int i = 0;i<m;i++) {
		mod3 += n[i] - '0';mod3 %= 3;
		num[i] = mod3;
	}
	if (mod3 == 0) ans++;
	x[0] = 1;
	for (int i = 0;i<m;i++) {
		ans += x[(num[i]-mod3+3) %3];
		x[num[i]]++;
	}
	ans--;
	cout << ans;
	return 0;
}
// Code cua Phuc ;-;
