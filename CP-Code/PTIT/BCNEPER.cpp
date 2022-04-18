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

string s;

signed main() {
	fastio
	int test;
	cin >> test;
	int n;
	while(test--) {
		cin >> n;
		cout << n << " ";
		cin >> s;
		int pos_1 = -1,pos_2;
		for (int i = s.size() - 1;i>0;i--) {
			if (s[i] > s[i-1]) {
				pos_1 = i - 1;
				break;
			}
		}		
		if (pos_1 == -1) cout << "BIGGEST" << EL
		else {
			//cout << pos_1;
			for (int i = s.size() - 1;i>0;i--) {
				if (s[i] > s[pos_1]){
					pos_2 = i;
					break;
				}
			}
			swap(s[pos_1],s[pos_2]);
			for (int i = 0;i<=min(pos_1,pos_2);i++) cout << s[i];
			for (int i = s.size() - 1;i>min(pos_1,pos_2);i--) {
				cout << s[i];
			}			
			cout << EL;
		}
	}

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
