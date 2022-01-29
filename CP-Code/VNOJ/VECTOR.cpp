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

int n,u,v;
pair<int,int> a[31];
vector<pair<int,int>> t1,t2;

void duyet(int i,int sx,int sy,int kt) {
	if (i > kt) {
		if (kt == n/2) t1.push_back({sx,sy});
		else t2.push_back({sx,sy});
		return;
	}
	for (int j = 0;j<=1;j++) {
		duyet(i+1,sx + a[i].fi * j,sy + a[i].se * j,kt);
	}
}


int find1(pair<int,int> x) {
	vector<pair<int,int>>::iterator up,low;
	up = upper_bound(t2.begin(),t2.end(),x);
	low = lower_bound(t2.begin(),t2.end(),x);
	return int(up - low);
}

signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) {
		cin >> a[i].fi >> a[i].se;
	}
	cin >> u >> v;
	duyet(1,0,0,n/2);
	duyet(n/2+1,0,0,n);
	sort(t2.begin(),t2.end());
	int res = 0;
	for (int i = 0;i<t1.size();i++) {
		int xx = u - t1[i].fi;
		int yy = v - t1[i].se;
		res += find1({xx,yy});
	}
	cout << res;
	
	


	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
