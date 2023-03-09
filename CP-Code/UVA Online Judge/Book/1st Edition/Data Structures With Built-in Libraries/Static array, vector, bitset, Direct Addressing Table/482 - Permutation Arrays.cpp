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
const int N = 1e7 + 5;

string s;
int timer = 0;
pair<int,string> a[N];

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
    	getline(cin,s);
		getline(cin,s);
    	s += ' ';
    	timer = 0;
    	string tmp = " ";
    	for (int i = 0;i < s.size();i++) {
    		if (s[i] >= '0' && s[i] <= '9') {
    			tmp += s[i];
    		} else {
    			a[++timer] = make_pair(stoi(tmp),-1);
    			tmp = "";
    		}
    	}
    	for (int i = 1;i <= timer;i++) {
	    	string x;
    		cin >> x;
    		a[i].se = x;
    	}
    	sort(a + 1,a + timer + 1);
    	for (int i = 1;i <= timer;i++) cout << a[i].se << EL;
    	if (test) cout << EL;
     	cin.ignore();
    }
 	
    return 0;
}
// agent pengin wants to take apio (with anya-san)
