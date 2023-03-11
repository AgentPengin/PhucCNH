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

struct cmp {
	bool operator () (pair<string,int> a,pair<string,int> b) const {
		if (a.se != b.se) return a.se < b.se;
		for (int i = 0;i < min(a.fi.size(),b.fi.size());i++) {
			if (a.fi[i] != b.fi[i]) return a.fi[i] < b.fi[i];
		}
		return a.fi.size() < b.fi.size();
	}
};

string title,food[N];
int n,m,b;
map<string,int> mp,fcost;
set<pair<string,int>,cmp> st;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
	int test;
	cin >> test;
	cin.ignore();
	while(test--) {
		mp.clear();
		st.clear();
		getline(cin,title);
		cin >> m >> n >> b;
		for (int i = 1;i <= m;i++){
			string ingre;
			int cost;
			cin >> ingre >> cost;
			mp[ingre] = cost;
		}
		cin.ignore();
		for (int i = 1;i <= n;i++) {
			getline(cin,food[i]);
			int k;
			cin >> k;
			int cost = 0;
			for (int j = 1;j <= k;j++) {
				string ingre;
				int num;
				cin >> ingre >> num;
				cost += mp[ingre] * num;
			}
			if (cost <= b) {
				st.insert({food[i],cost});
			}
			cin.ignore();
		}
		for (auto x : title) {
			cout << char(toupper(x));
		}
		cout << EL;
		if (st.size() == 0) {
			cout << "Too expensive!" << EL;
		} else {
			for (auto x : st) {
				cout << x.fi << EL;
			}
		}
		cout << EL;
	}	
    return 0;
}
// agent pengin wants to take apio (with anya-san)
