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

struct Dat{
	int AC,problem,penalty;
};

map<int,Dat> mp[10];
map<int,Dat> ans;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    int test;
    cin >> test;
    cin.ignore();
    cin.ignore();
    while(test--) {
    	for (int i = 1;i <= 9;i++) mp[i].clear();
    	ans.clear();
    	string str;
    	vector<Dat> ds;
    	while(getline(cin,str) && str.size() != 0) {
    		stringstream tmp(str);
    		string s;
    		vector<int> t;
    		char haha;
    		int checker = 0;
    		while(tmp >> s) {
    			if (checker <= 2) {
    				checker++;
    				string tm = s;
    				t.push_back(stoi(tm));
    			} else {
    				haha = s[0];
    			}
    		}
    		if (haha == 'R' || haha == 'U' || haha == 'E') {
    			if (mp[t[1]][t[0]].AC == 0) {
    				mp[t[1]][t[0]].AC = 0;
    			} else {
    				mp[t[1]][t[0]].AC = mp[t[1]][t[0]].AC;
    			}
    			continue;
    		}
    		if (haha == 'I') {
    			if (mp[t[1]][t[0]].AC == 0) mp[t[1]][t[0]].penalty += 20;
    		} else if (haha == 'C'){
    			if (mp[t[1]][t[0]].AC == 0) {
    				mp[t[1]][t[0]].AC = 1;
    				mp[t[1]][t[0]].penalty += t[2];
    			}
    		}
    	}
    	for (int i = 1;i <= 9;i++) {
    		for (auto x : mp[i]) {
    			if (x.se.AC == 1) {
	    			ans[x.fi].problem++;
	    			ans[x.fi].penalty += x.se.penalty;
    			} else {
    				ans[x.fi].problem = ans[x.fi].problem;
    				ans[x.fi].penalty += 0;
    			}
    		}
    	}
    	vector<Dat> v;
    	for (auto x : ans) {
    		// cout << x.fi << " " << x.se.problem << " " << x.se.penalty << EL;
    		v.push_back({x.fi,x.se.problem,x.se.penalty});
    	}
    	sort(v.begin(),v.end(),[&](Dat a,Dat b){
    		if (a.problem != b.problem) return a.problem > b.problem;
    		if (a.penalty != b.penalty) return a.penalty < b.penalty;
    		return a.AC < b.AC;
    	});
    	for (auto x : v) {
    		cout << x.AC << ' ' << x.problem << " " << x.penalty << EL;
    	}
    	
    	if (test) cout << EL;
    }
    return 0;
}
// agent pengin wants to take apio (with anya-san)
