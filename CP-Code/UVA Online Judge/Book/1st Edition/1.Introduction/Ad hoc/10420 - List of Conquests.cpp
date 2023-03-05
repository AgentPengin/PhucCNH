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

map<string,int> mp;
vector<pair<string,int>> ans;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
 	int beauty;
 	cin >> beauty;
 	cin.ignore();
 	while(beauty--) {
 		string s;
 		getline(cin,s);
 		string tmp = "";
 		for (int i = 0;i < s.size() && s[i] != ' ';i++) {
 			tmp += s[i];
 		}
 		mp[tmp]++;
 	} 	
 	for (auto x : mp) {
 		ans.push_back({x.fi,x.se});
 	}
 	sort(ans.begin(),ans.end(),[&](pair<string,int> a,pair<string,int> b){
 		// if (a.fi.size() > b.fi.size()) swap(a,b)
 		for (int i = 0;i < min(a.fi.size(),b.fi.size());i++) {
 			if (a.fi[i] != b.fi[i]) {
 				return a.fi[i] < b.fi[i];
 			}
 		}
 		return a.fi.size() < b.fi.size();
 	});
 	for (auto x : ans) {
 		cout << x.fi << " " << x.se << EL; 		
 	}
    return 0;
}
// agent pengin wants to take apio (with anya-san)
