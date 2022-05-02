#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(val) "["#val" = "<<(val)<<"] "

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

signed main() {
	fastio
	string s;
 	string words[] = {"dream", "dreamer", "erase", "eraser"};
 	cin >> s;
 	reverse(s.begin(),s.end());
 	for(int i=0; i<4; i++){
   		reverse(words[i].begin(),words[i].end());
 	}	
	int letterIndex = 0;
	while(letterIndex < (int)s.size()) {
		clog << db(letterIndex) << EL;
		if (s.substr(letterIndex,(int)(words[0].size())) == words[0]) {
			letterIndex += (int)(words[0].size());
		} else if (s.substr(letterIndex,(int)(words[1].size())) == words[1]) {
			letterIndex += (int)(words[1].size());
		} else if (s.substr(letterIndex,(int)(words[2].size())) == words[2]) {
			letterIndex += (int)(words[2].size());
		} else if (s.substr(letterIndex,(int)(words[3].size())) == words[3]) {
			letterIndex += (int)(words[3].size());
		} else return cout << "NO",0;
	}
	cout << "YES";
	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
