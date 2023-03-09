/**
 *    author:  AgentPengin ( Độc cô cầu bại )
 *    created: 23.12.2022 10:08:02
 *    too lazy to update time
**/
#include<bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define EL '\n'
#define NAME "NAME"
#define db(x) cerr << #x << " == " << x << endl

using namespace std;

const ll inf = 1e9 + 7;
const int N = 1e5 + 5;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    string s;
	while(cin >> s) {
		if (s == "#") break;
		string tmp = "";
		for (int i = 0;i < s.size();i++) {
			tmp += s[i];
		}
		sort(tmp.rbegin(),tmp.rend());
		if (tmp == s) {
			cout << "No Successor" << EL;
			continue;
		}
		vector<char> c;
		for (int i = 0;i < s.size();i++) c.push_back(s[i]);
		int cnt = 0;
		do {
			cnt++;
		} while(next_permutation(c.begin(),c.end()) && cnt <= 0);
		for (auto x : c) cout << x;
		cout << EL;
	}
 	
    return 0;
}
// agent pengin wants to take apio (with anya-san)
