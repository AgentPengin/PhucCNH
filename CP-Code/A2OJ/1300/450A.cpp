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

int n,m,x;
int a[1001];

void huhu(queue<pair<int,int>> kiu) {
	while(!kiu.empty()) {
		pair<int,int> res = kiu.front();
		cout << res.fi << "  " << res.se << EL;
		kiu.pop();
	}
}

signed main() {
	fastio
	queue<pair<int,int>> q;
	cin >> n >> m;
	for (int i = 1;i<=n;i++) {
		cin >> a[i];
		q.push({0,i});
	}
	while(!(q.size() == 1)) {
		pair<int,int> v = q.front();
		v.fi = v.fi + m;
		if (v.fi >= a[v.se]) q.pop();
		else {
			q.push({v.fi,v.se});
			q.pop();
		}
		//huhu(q);
		//cout << EL;
		
	}
	pair<int,int> res = q.front();
	cout << res.se;

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
