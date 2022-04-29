#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(val) "["#val" = "<<(val)<<"] "

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

int n,m;
char c[101][101];
pair<int,int> s,e;
bool check[101][101];
int step = 0;

bool check_onboard(int x,int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
 
bool go(int x,int y) {
	while(check_onboard(x,y) || c[x][y] == '.') {
		clog << db(x) << db(y) << EL;
		if (check[x][y] == true) return false;
		if (c[x][y] == '.') return false;
		else if (c[x][y] == 'x') return true;
		else if (!check_onboard(x,y)) return false;
		else {
			check[x][y] = true;
			step++;
			if (c[x][y] == '>') y++;
			else if (c[x][y] == '<') y--;
			else if (c[x][y] == '^') x--;
			else if (c[x][y] == 'v') x++;
		}
	}
	if (c[x][y] == 'x') return true;
	return false;
}

bool cmp(pair<int,char>a ,pair<int,char>b) {
	if (a.fi == b.fi) return a.se < b.se;
	else return a.fi < b.fi;
}

signed main() {
	fastio
	cin >> n >> m;
	for (int i = 1;i<=n;i++) {
		for (int j = 1;j<=m;j++) {
			cin >> c[i][j];
			if (c[i][j] == 'o') s = make_pair(i,j);
			if (c[i][j] == 'x') e = make_pair(i,j);
		}
	}
	vector<pair<int,char>> v;
	if (go(s.fi,s.se + 1) == 1) v.push_back({step,'E'});
	memset(check,false,sizeof check);
	step = 0;
	if (go(s.fi,s.se - 1) == 1) v.push_back({step,'W'});
	memset(check,false,sizeof check);	
	step = 0;
	if (go(s.fi + 1,s.se) == 1) v.push_back({step,'S'});
	memset(check,false,sizeof check);
	step = 0;
	if (go(s.fi - 1,s.se) == 1) v.push_back({step,'N'});
	if (v.empty()) cout << ":(";
	else {
		cout << ":)" << EL;
		sort(v.begin(),v.end(),cmp);
		cout << v[0].se;
	}
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
