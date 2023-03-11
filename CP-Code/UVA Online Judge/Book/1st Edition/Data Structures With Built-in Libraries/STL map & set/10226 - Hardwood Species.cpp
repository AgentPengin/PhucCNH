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

string s;
vector<pair<string,double>> alpha;
map<string,double> mp;
double cnt = 0;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
	int test;
	cin >> test;
	getline(cin,s);
	cin.ignore();
	while(test--) {
		cnt = 0;
		alpha.clear();
		mp.clear();
		while(getline(cin,s),s.size() != 0) {
			mp[s]++;
			cnt++;
		}
		for (auto x : mp) {
			alpha.push_back(make_pair(x.fi,x.se / cnt * (double)100.0));
		}
		sort(alpha.begin(),alpha.end(),[&](pair<string,double> a,pair<string,double> b){
			for (int i = 0;i < min(a.fi.size(),b.fi.size());i++) {
				if (a.fi[i] != b.fi[i]) return a.fi[i] < b.fi[i];
			}
			return a.fi.size() < b.fi.size();
		});
		for (auto x : alpha) cout << x.fi << " " << fixed << setprecision(4) << x.se << EL;
		if (test) cout << EL;
	} 	
    return 0;
}
// agent pengin wants to take apio (with anya-san)
