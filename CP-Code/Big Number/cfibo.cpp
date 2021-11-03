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
const int NMAX = 1001;

string f[NMAX];
string a,b;

int op(string a,string b) {
	while (a.length() < b.length()) a = "0" + a;
	while (a.length() > b.length()) b = "0" + b;
	if (a > b) return 1;
	else if (a == b) return 0;
	else return -1;
}

string sum(string a,string b) {
	int res,mem = 0;
	string c = "";
	while (a.size() < b.size()) a = "0" + a;
	while (a.size() > b.size()) b = "0" + b;
	for (int i = a.size()-1;i>=0;i--) {
		res = a[i] + b[i] - 96 + mem;
		c = char(res%10 + 48) + c; 
		mem = res / 10;
	}
 	if (mem != 0) c = "1" + c;
	return c;
}

void generate() {
	f[0] = "0";
	f[1] = "1";
	f[2] = "1";
	for (int i = 3;i<=999;i++) {
		f[i] = sum(f[i-1],f[i-2]);
	}
}

int main() {
	fastio
	cin >> a >> b;
	generate();
	ll i = 0,res = 1;
	while (op(f[i],a) == -1) i++;
	while (op(f[i],b) == -1) {
		i++;
		res++;
	}
	if (op(a,"1") == 0|| op(a,"0") == 0) res--;
 	if (op(f[i],b) != 0) cout << res - 1;
 	else cout << res;
	return 0;
}
// Code cua Phuc ;-;
