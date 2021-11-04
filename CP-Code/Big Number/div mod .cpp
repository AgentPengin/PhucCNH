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

string m;
int n;

string divs(string a,int b) {
	int s,mem = 0;
	string c = "";
	for (int i = 0;i<a.size();i++) {
		mem = mem*10 + a[i] - 48;
		s = mem/b;
		mem = mem % b;
		c = c + char(s+48);
	}
	while(c.size() > 1 && c[0] == '0') c.erase(0,1);
	return c;
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
	cin >> m >> n;
	cout << div(m,n) << EL;
	cout << mod(m,n);
	return 0;
}
// Code cua Phuc ;-;
