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


bool f(string s) {
	ll res = 0;
	for (int i = 0;i<s.size();i++) {
		res += int(s[i] - 48);
	}
	if (res %9 == 0) return true;
	else return false;
}

int main() {
	fastio
	string n;
	cin >> n;
	if (f(n)) cout << "YES";
	else cout << "NO";
 	
	return 0;
}
// Code cua Phuc ;-;
