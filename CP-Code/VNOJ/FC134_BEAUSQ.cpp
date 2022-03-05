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
const ll MAX = 1000002;
const ll NMAX = 50005;

using namespace std;

ll prime[MAX] = {0};
ll n,q;
ll a[NMAX];
ll primeNum[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

vector<ll> tree[200000];
vector<ll> zero(101,0);

vector<ll> operator+(const vector<ll>& a,const vector<ll>& b) {
	vector<ll> res(101,0);
 	for (ll i = 0;i<a.size();i++) {
 		res[i] = a[i] + b[i];
 	}
 	return res;
}

void factorial_prime() {
	for (ll i = 2;i< MAX;i+=2) prime[i] = 2;
	for (ll i = 3;i< MAX;i+=2) {
		if (!prime[i]) {
			prime[i] = i;
			for (int j = i;i*j<MAX;j+=2) if (!prime[i*j]) prime[i*j] = i;	
		}
	} 
}

vector<ll> primeFacToVector(ll n) {
	vector<ll> res(101,0);
	while(n != 1) {
		ll k = prime[n];
		while(n % k == 0) {
			n /= k;
			res[k]++;
		}
	}
	return res;
}

void buildTree(ll id,ll left,ll right) {
	if (left == right) {
		tree[id] = primeFacToVector(a[left]);
		return;
	}
	ll mid = (left + right) >> 1;
	buildTree(id << 1,left,mid);
	buildTree((id << 1) + 1,mid + 1,right);
	tree[id] = tree[id << 1] + tree[(id << 1) + 1];
}

vector<ll> getVal(ll id,ll left,ll right,ll u,ll v) {
	if (v < left || u > right || right < left) return zero;
	if (u <= left && v >= right) return tree[id];
	ll mid = (left + right) >> 1;
	return getVal(id << 1,left,mid,u,v) + getVal((id << 1) + 1,mid + 1,right,u,v);
}

void update(ll id,ll left,ll right,ll index,vector<ll> val) {
	if (index < left || index > right || left > right) return;
	
	if (left == right) {
		tree[id] = tree[id] + val;
		return;
	}
	ll mid = (left + right) >> 1;
	update(id << 1,left,mid,index,val);
	update((id << 1) + 1,mid + 1,right,index,val);
	tree[id] = tree[id << 1] + tree[(id << 1) + 1];
}

signed main() {
	fastio
	factorial_prime();
	cin >> n;
	for (ll i = 1;i<=n;i++) cin >> a[i];
	buildTree(1,1,n);
	cin >> q;
	while(q--) {
		int request;
		cin >> request;
		if (request == 1) {
			ll left,right;
			cin >> left >> right;
			bool check = true;
			vector<ll> res = getVal(1,1,n,left,right);
			for (ll i = 0;i<25;i++) {
				if (res[primeNum[i]] & 1) {
					check = false;
					break;
				}
			}
			cout << (check ? "YES\n" : "NO\n");
		} else {
			ll id,val;
			cin >> id >> val;
			vector<ll> vecPrime = primeFacToVector(val);
			update(1,1,n,id,vecPrime);
		}
	}
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
