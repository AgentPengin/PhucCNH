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

using namespace std;

struct pack{
	unsigned int w,v;
};

void operator += (pack &a, const pack &b) {
	a.w += b.w;
	a.v += b.v;
}

bool operator < (const pack &a, const pack &b) {
	return a.w < b.w;
}


vector<pack> generate(const vector<pack> &a, unsigned int m) {
	vector<pack> res(1 << a.size());
	int n = 0;
	for (int i = 0;i<(int)res.size();i++) {
		pack tmp = {0,0};
		for (int k = 0;k < (int)a.size();k++) {
			if (i & (1 << k)) tmp += a[k];
		}
		if (tmp.w <= m) res[n++] = tmp;
	}
	res.resize(n);
	sort(res.begin(),res.end());
	return res;
}

signed main() {
	fastio
	unsigned int n,m;
	cin >> n >> m;
	int n1 = n/2;
	int n2 = n - n1;;
	vector<pack> a(n1),b(n2);
	for (pack &x : a) cin >> x.w >> x.v;
	for (pack &x : b) cin >> x.w >> x.v;
	vector<pack> f(generate(a,m));
	vector<pack> g(generate(b,m));
	unsigned int result = 0;
	unsigned int max_value = 0;
	for (int i = f.size()-1,j = 0;i>=0;i--) {
		while(j<(int)g.size() && f[i].w + g[j].w <= m) {
			max_value = max(max_value,g[j].v);
			j++;
		} 
		result = max(result,max_value + f[i].v);
	}
	cout << result;
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
