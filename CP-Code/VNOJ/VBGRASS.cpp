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

const int dx[] = { 0, -1, 0, 1 };
const int dy[] = { 1, 0, -1, 0 };

using namespace std;

int r,c;
string s[10005];

void dfs(int i,int j) {
	s[i][j] = '.';
	if (i < r && s[i+1][j] == '#') dfs(i + 1,j);
    if (j < c && s[i][j+1] == '#') dfs(i,j + 1);
    if (i > 0 && s[i-1][j] == '#') dfs(i - 1,j);
    if (j > 0 && s[i][j-1] == '#') dfs(i,j - 1);
}

signed main() {
	fastio
	//memset(check,false,sizeof(check));
	cin >> r >> c;
	string tmp;
	cin >> tmp;
	//cout << tmp << EL;
	s[0] = tmp;
	for (int i = 1;i<r;i++) cin >> s[i];
	int res = 0;
	for (int i = 0;i<r;i++) {
		for (int j = 0;j<c;j++) {
			if (s[i][j] == '#') {
				dfs(i,j);
				res++;
				//cout << res << " " << i << " " << j << EL;
			}
		}
	}
	cout << res;
	

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
