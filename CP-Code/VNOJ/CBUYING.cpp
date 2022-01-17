#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define llll pair<long long,long long>
#define fi first
#define se second
#define N 10000000
using namespace std;

long long b;
llll a[N];

int main() {
	fastio
	int n;
	cin >> n;
	cin >> b;
	for (int i = 0;i<n;i++) cin >> a[i].fi >> a[i].se;
	sort(a,a+n);
	int i = 0;
	long long sum = 0,sl = 0;
	while (i < n) {
		sl = min(a[i].se,b/a[i].fi);
		b = b -sl*a[i].fi;
		sum = sum+sl;
		i++;
	}
	
	cout << sum;
	
	
}
