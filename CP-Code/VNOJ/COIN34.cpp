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

int n = 34,f[35],x;
vector<pair<int,int>> t1,t2;
vector<pair<int,int>>::iterator up;

void duyet(int i,int sum,int cnt,int kt) {
	if (i > kt) {
		if (kt == n/2) t1.push_back({sum,cnt});
		else t2.push_back({sum,cnt});
		return;
	}
	for (int j = 0;j<=1;j++) {
		duyet(i+1,sum + j * f[i],cnt + j,kt);
	}
}

int process(int x) {
	int res = -1;
	for (int i = 0;i<t1.size();i++) {
		up = upper_bound(t2.begin(),t2.end(),pair<int,int>(x - t1[i].fi,inf));
		int pos = int(up - t2.begin()) - 1;
		if (t2[pos].fi == x - t1[i].fi) res = max(res,t2[pos].se + t1[i].se);
	}
	return res;
}

signed main() {
	fastio
	f[1] = 2;
	f[2] = 3;
	f[3] = 5;
	for (int i = 4;i<=34;i++) {
		f[i] = f[i-1] + f[i-2] + f[i-3];
	}
	duyet(1,0,0,n/2);
	duyet(n/2+1,0,0,n);
	sort(t2.begin(),t2.end());
	int test;
	cin >> test;
	for (int i = 1;i<=test;i++) {
		cin >> x;
		cout << "Case #" << i << ": " << process(x) << EL;
	}
	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
