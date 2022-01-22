#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
#define fi first
#define se second 
#define pb push_back
#define EL "\n"
#define FOR(i,a,b) for (int i = a;i<=b;i++) 
#define DEC(i,a,b) for (int i = a;i>=b;i--)

typedef pair<int,int> pii;
typedef vector<ll> vll;
typedef vector<int> vi;


const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

vll a,t;
ll m,n,k,x;
int main() {
	fastio;
	cin >> m >> n >> k;
	a.push_back(0);
	for (int i = 1;i<=m;i++) {
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	t.resize(m+1);
	for (int i = 1; i <= m; i++){
		t[i] = t[i-1]+a[i];
	}
	ll sum = -2;
	for (int i = 1; i <= m-n+1; i++) {
		// cout<<a[i]<<" "<<a[i+n-1]<<endl;
		if (a[i+n-1] - a[i] <= k) 
			sum = max(sum,t[i+n-1] - t[i-1]);
	}
	cout << sum;
	return 0;
}
