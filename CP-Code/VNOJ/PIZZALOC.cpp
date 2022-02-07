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

struct location{
	int x,y,person;
};

int k,r,m,n;
location b[101];
pair<int,int> a[21];
vector<int> List[101];
int res = -inf;
int check[101];

bool check_location(int x1,int y1,int x2,int y2,int r) {
	double edge_1 = abs(x1 - x2);
	double edge_2 = abs(y1 - y2);
	double hypotenuse = sqrt(edge_1 * edge_1 + edge_2 * edge_2);
	if (hypotenuse <= r) return true;
	else return false;
}

void back_track(int i,int k,int tmp,int cnt,int m) {
	if (i > m || cnt >= k) {
		res = max(res,tmp);
		return;
	}
	for (auto x : List[i]) {
		if (check[x] == 0) tmp += b[x].person;
		check[x]++;
	}
	back_track(i+1,k,tmp,cnt+1,m);
	for (int j = 0;j<List[i].size();j++) {
		check[List[i][j]]--;
		if (check[List[i][j]] == 0) tmp = tmp - b[List[i][j]].person;
	}	
	back_track(i+1,k,tmp,cnt,m);
}

signed main() {
	fastio
	cin >> k >> r >> m;
	for (int i = 1;i<=m;i++) cin >> a[i].fi >> a[i].se;
	cin >> n;
	for (int i = 1;i<=n;i++) cin >> b[i].x >> b[i].y >> b[i].person;
	for (int i = 1;i<=m;i++) {
		for (int j = 1;j<=n;j++) {
			if (check_location(a[i].fi, a[i].se, b[j].x, b[j].y, r)) List[i].push_back(j); 
		}
	}
	
	back_track(1,k,0,0,m);
	cout << res;
	
	 	


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
