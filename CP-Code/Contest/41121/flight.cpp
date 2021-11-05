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
#define debug "#:        "


const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 31;

int a[NMAX];

string sum(string a,string b) {
	string c = "";
	int res = 0,mem = 0;
	while(a.size() < b.size()) a = "0" + a;
	while(a.size() > b.size()) b = "0" + b;
	for (int i = a.size() - 1;i>=0;i--) {
		res = a[i] + b[i] - 96 + mem;
		c = char(res % 10 + 48) + c;
		mem = res / 10;
	}
	if (mem != 0) c = "1" + c;
	return c;
}
string multi(string a,int k) {
	string c = "";
	int mem = 0,s;
	for (int i = a.size() - 1;i>=0;i--) {
		s = (a[i] - 48) * k + mem;
		mem = s/10;
		c = char(s%10 + 48) + c;
	}
	string tmp;
	if (mem > 0) tmp = to_string(mem);
	else tmp = "";
	c = tmp + c;
	return c;
}

int mods(string a,int b) {
	int mem = 0;
	for (int i = 0;i<a.size();i++) {
		mem = (mem * 10 + a[i] - 48) % b;
	}
	return mem;
}
int gcd(int a,int b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
int main() {
	fastio
	short n;
	cin >> n;
	string bc = "1";
	for (int i = 0;i<n;i++) cin >> a[i];
	for (int i = 0;i<n;i++) {
		int tmp = mods(bc,a[i]);
		tmp = gcd(tmp,a[i]);
		bc = multi(bc,a[i]/tmp);
	}
	cout << bc;
	return 0;
}
// Code cua Phuc ;-;
