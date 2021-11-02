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
string tru(string a,string b) {
	int s;
	string c = "";
	int mem = 0;
	while (a.size() < b.size()) a = "0" + a;
	while (a.size() > b.size()) b = "0" + b;
	for (int i = a.size()-1;i>=0;i--) {
		s = a[i] - b[i] - mem;
		if (s < 0) {
			s += 10;
			mem = 1;
		} else mem = 0;
		c = char(s+48) + c;
	}
	while ((c.size() > 1) && c[0] == '0') c.erase(0,1);
	return c;
}


string sumcs(string n) {
	ll res = 0;
	for (int i = 0;i<n.size();i++) {
		res += n[i] - '0';
	}
	return to_string(res);
}

string solve(string a) {
	 string i = a;
	 while (sum(i,sumcs(i)) != a) {
	 	i = tru(i,"1");
	 }
	 return i;
	
}

int main() {
	fastio
	string n;
	cin >> n;
	cout << solve(n);
 	
	return 0;
}
// Code cua Phuc ;-;
