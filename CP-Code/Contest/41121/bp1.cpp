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
	string res = "0";
	for (int i =0;i<k;i++) res = sum(res,a);
	return res;
}
string multiBig(string a,string b) {
	string s = "",tmp;
	int m = -1;
	for (int i = a.size() - 1;i>=0;i--) {
		m++;
		tmp = multi(b,a[i]-48);
		for (int j = 1;j<=m;j++) tmp = tmp + '0';
		s = sum(s,tmp);
	}
	return s;
}

int main() {
	fastio
	string s;
	short t;
	int n;
	cin >> t;
	while(t--) {	
		cin >> n;
		s = "";
		for (int i = 0;i<n;i++) s = s + "1";
		cout << multiBig(s,s) << EL;
	}
	return 0;
}
// Code cua Phuc ;-;
