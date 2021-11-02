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

string sum(string a,string b) {
	string c = "";
	int res = 0, mem = 0;
	while (a.size() < b.size()) a = "0" + a;
	while (a.size() > b.size()) b = "0" + b;
	for (int i = a.size() - 1;i>=0;i--) {
		res = a[i] + b[i] - 96 + mem;
		mem = res / 10;
		c = char(res%10 + 48) + c;
	}
	if (mem != 0) c = "1" + c;
	return c;
}
int main() {
	fastio
	string a,b;
	cin >> a >> b;
	cout << sum(a,b);
	return 0;
}
// Code cua Phuc ;-;
