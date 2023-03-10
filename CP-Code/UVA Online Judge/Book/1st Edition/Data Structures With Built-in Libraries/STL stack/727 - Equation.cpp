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

int Priority(char c) {
    switch (c) {
        case '(': return 1; break;
        case '+': return 2; break;
        case '-': return 2; break;
        case '*': return 3; break;
        case '/': return 3; break;
    }
}

signed main() {
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    int test,i;
    char s[10],c;
    cin >> test;
    gets(s);
    gets(s);
    while(test--) {
    	stack<char> st;
    	while(gets(s) && strlen(s)) {
    		c = s[0];
    		if (c == ' ') break;
    		if (c == '(') {
    			st.push(c);
    		} else if (c == '+' || c == '-' || c == '*' || c == '/') {
    			while(!st.empty() && Priority(c) <= Priority(st.top())) {
    				cout << st.top();
    				st.pop();
    			}
    			st.push(c);
    		} else if (c == ')') {
    			while(st.top() != '(') {
    				cout << st.top();
    				st.pop();
    			}
    			st.pop();
    		} else cout << c;
    	}
    	while(!st.empty()) {
    		cout << st.top();st.pop();
    	}
    	cout << EL;
    	if (test) cout << EL;
    }
    return 0;
}
// agent pengin wants to take apio (with anya-san)
