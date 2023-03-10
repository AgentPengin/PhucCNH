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
 	int test;
 	cin >> test;
 	cin.ignore();
 	while(test--) {
 		string s;
 		getline(cin,s);
 		if (s.size() == 0) {
 			cout << "Yes" << EL;
 			continue;
 		}
 		stack<char> st;
 		bool flag = true;
 		for (int i = 0;i < s.size();i++) {
 			if (s[i] == '(' || s[i] == '[') st.push(s[i]);
 			else if (s[i] == ')'){
 				if (st.empty()) {
 					flag = false;
 					break;
 				}
 				if (st.top() == '[') {
 					flag = false;
 					break;
 				}
 				st.pop();
 			} else {
 				if (st.empty()) {
 					flag = false;
 					break;
 				}
 				if (st.top() == '(') {
 					flag = false;
 					break;
 				}
 				st.pop();
 			}
 		}
 		if (flag && st.empty()) cout << "Yes";
 		else cout << "No";
 		cout << EL;
 	}
    return 0;
}
// agent pengin wants to take apio (with anya-san)
