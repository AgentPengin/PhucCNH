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
const int NMAX = 1001;

string f[NMAX];
string a,b;

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
string divs(string a,int b) {
	int s,mem = 0;
	string c =  "";
	for (int i = 0;i<a.size();i++) {
		mem = mem*10 + a[i] - 48;
		s = mem/b;
		mem = mem % b;
		c = c + char(s+48);
	}
	while(c.size() > 1 && c[0] == '0') c.erase(0,1);
	return c;
}
string tru(string a,string b) {
	while(a.size() < b.size()) a = "0" + a;
	while(a.size() > b.size()) b = "0" + b;
	int s;
	string c = "";
	int mem = 0;
	for (int i = a.size() -1;i>=0;i--) {
		s = a[i] - b[i] - mem;
		if (s < 0) {
			s += 10;
			mem = 1;
		} else mem = 0;
		c = char(s + 48) + c;
	}
	while(c.size() > 1 && c[0] == '0') c.erase(0,1);
	return c;
}
void generate() {
	f[1] = "1";
	f[2] = "1";
	for (int i = 3;i<=999;i++) {
		f[i] = sum(f[i-1],f[i-2]);
	}
}

int main() {
	fastio
	int n;
	cin >> n;
	generate();
	cout << f[n+2];
	return 0;
}
// Code cua Phuc ;-;
