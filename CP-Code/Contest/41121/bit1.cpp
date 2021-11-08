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
#define time_start() auto start = chrono::steady_clock::now(); 
#define time_end() auto end = chrono::steady_clock::now();
#define time_use() cout << EL << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

string sum(string a,string b) {
	string c = "";
	int res = 0,mem = 0;
	while (a.size() < b.size()) a = "0" + a;
	while (a.size() > b.size()) b = "0" + b;
	for (int i = a.size() - 1;i>=0;i--) {
		res = a[i] + b[i] - 96 + mem;
		c = char(res%10+48) + c;
		mem = res / 10;
	}
	if (mem != 0) c = "1" + c;
	return c;
}
string multi(string a,int k) {
	string c = "";
	int mem = 0,s;
	for (int i = a.size()-1;i>=0;i--){
		s = (a[i] - 48) * k + mem;
		c = char(s % 10 + 48) + c;
		mem = s / 10;
	}
	string tmp = "";
	if (mem > 0) tmp = to_string(mem);
	c = tmp + c;
	return c;
}
string multiBig(string a,string b) {
	string s = "",tmp;
	int m = -1;
	for (int i = a.size() -1;i>=0;i--) {
		m++;
		tmp = multi(b,a[i] - 48);
		for (int j = 1;j<=m;j++) tmp = tmp + '0';
		s = sum(s,tmp);
	}
	return s;
}
string div(string a,int b) {
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
string tru(string a, string b) {
    while (a.size() > b.size()) b = "0" + b;
    while (a.size() < b.size()) a = "0" + a;
    int s;
    string c = "";
    int mem = 0;
    for (int i=a.size()-1; i>=0; i--) {
        s = a[i] - b[i] - mem;
        if (s < 0) {
            s += 10;
            mem = 1;
        }
        else mem = 0;
        c = char(s+48) + c;
    }
    while ((c.size() > 1) && c[0] == '0') c.erase(0, 1);
    return c;
}

string power(string a,int k) {
	string res = "1";
	for (int i = 0;i<k;i++) {
		res = multiBig(res,a);
	}
	return res;
}
string dequi(ll n) {
	ll k = log2(n);
	if (n == 1) return "1";
	if (n == 0 ) return "0";
	if (n == 2) return "2";
	if (n == 3) return "4";
	string p = sum(sum(div(multi(power("2",k),k),2),sum(tru(to_string(n),power("2",k)),"1")),dequi(stol(tru(to_string(n),power("2",k)))));
	return p;
}
int main() {
	fastio
	ll n;
	cin >> n;
	/*while (t--) {
	}*/
	cout << dequi(n) << EL;
	return 0;
}
// Code cua Phuc ;-;
