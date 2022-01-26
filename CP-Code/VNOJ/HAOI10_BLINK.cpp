#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)


const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 31;

using namespace std;

int n;
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
string divs(string a,int b) {
	int s,mem = 0;
	string c = "";
	for (int i = 0;i<a.size();i++) {
		mem = mem * 10 + a[i] - 48;
		s = mem / b;
		mem = mem % b;
		c = c + char(s+48);
	}
	while(c.size() > 1 && c[0] == '0') c.erase(0,1);
	return c;
}

int mods(string a,int b) {
	int mem = 0;
	for (int i = 0;i<a.size();i++) {
		mem = (mem * 10 + a[i] - 48) % b;
	}
	return mem;
}

int gcd(string a,int b) {
	if (b == 0) return stoi(a);
	return gcd(to_string(b),mods(a,b));
}
ll a[31];
signed main() {
	fastio
	ll n;
	cin >> n;
	cin >> a[1];
	string lck = to_string(a[1]);
	ll gcn = a[1];
	
	for (int i = 2;i<=n;i++) {
		cin >> a[i];
		gcn = gcd(lck,a[i]);
		lck = divs(multi(lck,a[i]),gcn);	
	}
	cout << lck;

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
