#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(val) "["#val" = "<<(val)<<"] "

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

signed main() {
	fastio
	string a,b,c;
	cin >> a >> b >> c;
	int i = 0,j = 0,k = 0;
	int tmp = 1;
	while(true) {
		if (tmp == 1) {
			if (i == (int)a.size()) return cout << "A",0;
			if (a[i] == 'a') tmp = 1;
			else if (a[i] == 'b') tmp = 2;
			else if (a[i] == 'c') tmp = 3;
			i++;
		} else if (tmp == 2) {
			if (j == (int)b.size()) return cout << "B",0;
			if (b[j] == 'a') tmp = 1;
			else if (b[j] == 'b') tmp = 2;
			else if (b[j] == 'c') tmp = 3;
			j++; 
		} else if (tmp == 3) {
			if (k == (int)c.size()) return cout << "C",0;
			if (c[k] == 'a') tmp = 1;
			else if (c[k] == 'b') tmp = 2;
			else if (c[k] == 'c') tmp = 3;
			k++;
		}	
	}
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
