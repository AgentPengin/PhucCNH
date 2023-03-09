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
	int points,wins,goalDiff,goalScored,gamePlayed;
	int ties,losses,goalAgainst;
};

string tournament_name,team[33];
int teamNum,gameNum;

map<string,Dat> mp;
vector<string> v;

bool cmp(string a,string b) {
	Dat d1 = mp[a];
	Dat d2 = mp[b];
	if (d1.points != d2.points) return d1.points > d2.points;
	if (d1.wins != d2.wins) return d1.wins > d2.wins;
	if (d1.goalDiff != d2.goalDiff) return d1.goalDiff > d2.goalDiff;
	if (d1.goalScored != d2.goalScored) return d1.goalScored > d2.goalScored;
	if (d1.gamePlayed != d2.gamePlayed) return d1.gamePlayed < d2.gamePlayed;
	for (int i = 0;i < min(a.size(),b.size());i++) {
		if (tolower(a[i]) != tolower(b[i])) return tolower(a[i]) < tolower(b[i]);
	}
	return a.size() < b.size();
}

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
 		v.clear();
 		getline(cin,tournament_name);
 		cin >> teamNum;
 		cin.ignore();
 		for (int i = 1;i <= teamNum;i++) {
 			getline(cin,team[i]);
 			v.push_back(team[i]);
 		}
 		cin >> gameNum;
 		cin.ignore();
 		for (int i = 1;i <= gameNum;i++) {
 			string game;
 			getline(cin,game);
 			int j = 0;
 			string tmp1 = "",tmp2 = "",scoreA = "",scoreB = "";
 			for (j = 0;j < game.size() && game[j] != '#';j++) {
 				tmp1 += game[j];
 			}
 			j++;
 			for (j;j < game.size() && game[j] != '@';j++) {
 				scoreA += game[j];
 			}
 			j++;
 			for (j;j < game.size() && game[j] != '#';j++) {
 				scoreB += game[j];
 			}
 			j++;
 			for (j;j < game.size();j++) {
 				tmp2 += game[j];
 			}
			int score1 = stoi(scoreA);
			int score2 = stoi(scoreB);
			if (score1 > score2) {
				mp[tmp1].points += 3;
				mp[tmp1].wins++;
				mp[tmp2].losses++;
			} else if (score1 == score2) {
				mp[tmp1].points++;
				mp[tmp2].points++;
				mp[tmp1].ties++;
				mp[tmp2].ties++;
			} else if (score1 < score2) {
				mp[tmp2].points+=3;
				mp[tmp1].losses++;
				mp[tmp2].wins++;
			}
			mp[tmp1].gamePlayed++;
			mp[tmp2].gamePlayed++;
			mp[tmp1].goalScored += score1;
			mp[tmp2].goalScored += score2;
			mp[tmp1].goalAgainst += score2;
			mp[tmp2].goalAgainst += score1;
			mp[tmp1].goalDiff += score1 - score2;
			mp[tmp2].goalDiff += score2 - score1;
 		}
 		sort(v.begin(),v.end(),cmp);
 		cout << tournament_name << EL;
 		for (int i = 1;i <= teamNum;i++) {
 			team[i] = v[i - 1];
 			cout << i << ") " << team[i] << " " << mp[team[i]].points << "p, " << mp[team[i]].gamePlayed << "g (" << mp[team[i]].wins << "-" << mp[team[i]].ties << "-" << mp[team[i]].losses << "), " << mp[team[i]].goalDiff << "gd (" << mp[team[i]].goalScored << "-" << mp[team[i]].goalAgainst << ")" << EL;   
 		}
 		if (test) cout << EL;
 	}
    return 0;
}
// agent pengin wants to take apio (with anya-san)
