#include<iostream>
#include<iomanip>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<vector>
#include<utility>
#include<set>
#include<queue>

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> bigNum;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
#define fi first
#define se second 
#define pb push_back
#define EL "\n"
#define FOR(i,a,b) for (int i = a;i<=b;i++) 
#define DEC(i,a,b) for (int i = a;i>=b;i--)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b))*b

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 1001;

int n;
string s;

int main() {
	fastio;
	cin >> n;
	cin >> s;
	string tmp;
	string m = "";
	for (int i = 0;i<1000;i++) m = '9'+m;
	for (int i = 0;i<n;i++) {
		tmp = "";
		for (int i = 0;i<n-1;i++) {
				tmp = tmp + s[i];
		}
		tmp = s[n-1] + tmp;
		s = tmp;
		if (tmp < m) m = tmp;
		for (int j = 1;j<=9;j++) {
			for (int k = 0;k<tmp.size();k++) {
				tmp[k] = tmp[k] + 1;
				if (tmp[k] > '9') tmp[k] = '0';
			}		
			if (tmp < m) m = tmp;
		}
	}
	cout << m;
	return 0;
}
// Code cua Phuc ;-;
