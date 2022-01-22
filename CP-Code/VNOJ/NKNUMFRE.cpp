#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
#define fi first
#define se second 
#define pb push_back
#define EL "\n"
#define FOR(i,a,b) for (int i = a;i<=b;i++) 
#define DEC(i,a,b) for (int i = a;i>=b;i--)

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

int rev(int n) {
	int res = 0;
	while (n != 0) {
		res = res * 10 + n%10;
		n /=10;
		
	}
	return res;
}

int main() {
	fastio
	int a,b,count =0;
	cin >> a >> b;
	FOR(i,a,b) if (__gcd(i,rev(i)) == 1) count++;
 	cout << count;
	return 0;
}
