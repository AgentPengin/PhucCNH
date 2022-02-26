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
const int N = 1e5 + 10;

using namespace std;

int n,m;
struct Node{
	int val,lazy;

} node[N *4];

void lazyUpdate(int id,int left,int right) {
	if (node[id].lazy) {
		int mid = (left + right) >> 1;
		node[id << 1].val = mid - left + 1 - node[id * 2].val;
		node[id << 1].lazy = (node[id << 1].lazy + 1) % 2;
		node[(id << 1) + 1].val = right - mid - node[(id << 1) + 1].val;
		node[(id << 1) + 1].lazy = (node[(id << 1) + 1].lazy + 1) % 2;
	}
	node[id].lazy = 0;	
}

void update(int id,int left,int right,int u,int v) {
	if (v < left || u > right) return;
	if (u <= left && v >= right) {
		node[id].val = right - left + 1 - node[id].val;
		node[id].lazy = (node[id].lazy + 1) % 2;
		return;
	}
	lazyUpdate(id,left,right);
	int mid =(left + right)/2;
	update(id << 1,left,mid,u,v);
	update((id << 1) + 1,mid + 1,right,u,v);
	node[id].val = node[id << 1].val + node[(id << 1) + 1].val;
}

int getVal(int id,int left,int right,int u,int v) {
	if (v < left || u > right) return 0;
	if (u <= left && v >= right) return node[id].val;
	lazyUpdate(id,left,right);
	int mid = (left + right)/2;
	return getVal(id << 1,left,mid,u,v) + getVal((id << 1) + 1,mid + 1,right,u,v);
	
	
}

signed main() {
	fastio
	cin >> n >> m;
	while(m--) {
		int request,x,y;
		cin >> request >> x >> y;
		if (!request) update(1,1,n,x,y);
		else cout << getVal(1,1,n,x,y) << EL;
	}

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
