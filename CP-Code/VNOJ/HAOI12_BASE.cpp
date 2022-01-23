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

signed main() {
	fastio
	string s;
	getline(cin,s);
	if (s.size() % 4 == 0) {
		for (int i = 0;i<s.size();i+=4) {
			int tmp = (int(s[i]) - 48)*(1 << 3);
			tmp = tmp + (int(s[i+1]) - 48)*(1 << 2);
			tmp = tmp + (int(s[i+2]) - 48) *(1 << 1);
			tmp = tmp + (int(s[i+3]) - 48) *(1 << 0);
			if (tmp < 10) cout << tmp;
			else {
				if (tmp == 10) cout << "A";
				else if (tmp == 11) cout << "B";
				else if (tmp == 12) cout << "C";
				else if (tmp == 13) cout << "D";
				else if (tmp == 14) cout << "E";
				else if (tmp == 15) cout << "F";	
			}
		}
	} else {
		int n = s.size() % 4;
		string str = "";
		for (int i = n;i<s.size();i+=4) {
			int tmp = (int(s[i]) - 48)*(1 << 3);
			tmp = tmp + (int(s[i+1]) - 48)*(1 << 2);
			tmp = tmp + (int(s[i+2]) - 48) *(1 << 1);
			tmp = tmp + (int(s[i+3]) - 48) *(1 << 0);
			if (tmp < 10) str = str + to_string(tmp);
			else {
				if (tmp == 10) str = str + "A";
				else if (tmp == 11) str = str + "B";
				else if (tmp == 12) str = str + "C";
				else if (tmp == 13) str = str + "D";
				else if (tmp == 14) str = str + "E";
				else if (tmp == 15) str = str + "F";	
			}
		}
		int tmp = 0;
		for (int i = n-1;i>=0;i--) {
			tmp += (int(s[i]) - 48) * (1 << (n - i - 1));
		}
		if (tmp < 10) str = to_string(tmp) + str;
		cout << str << EL;
	}

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
