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

int k,n;
string m;

string sum(string a,string b) {
	int res = 0,mem = 0;
	string c = "";
	while (a.size() > b.size()) b = "0" + b;
	while (a.size() < b.size()) a = "0" + a;
	for (int i = a.size()-1;i>=0;i--) {
		res = a[i] + b[i] - 96 + mem;
		c = char(res % 10 + 48) + c;	
		mem = res / 10;
	}
	if (mem != 0) c = "1" + c;
	return c;
}
string multi(string a,int k) {
	string res = "0";
	for (int i = 0;i<k;i++) res = sum(res,a);
	return res;
}
void solve() {
	int t = stoi(m);
	for (int i = 0;i<n-1;i++) {
		m = multi(m,t);
	}
	for (int i = m.size() - k;i<m.size();i++) cout << m[i];
}


int main() {
	fastio
	cin >> m;
	cin >> n >> k;
	solve();
	return 0;
}
// Code cua Phuc ;-;
