#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n"
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int NMAX = 1e6 + 10;

using namespace std;

struct Rank{
	string name;
	int task,score = 0;
} s[NMAX];

int n;

bool cmp(Rank a,Rank b) {
	if (a.task != b.task) return a.task > b.task;
	else return a.score < b.score;
}

signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) {
		cin >> s[i].name;
		int x1,y1,x2,y2,x3,y3,x4,y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		if (y1 != 0) {
			s[i].task++;
			s[i].score += (x1 - 1) * 20 + y1;
		}
		if (y2 != 0) {
			s[i].task++;
			s[i].score += (x2 - 1) * 20 + y2;
		}
		if (y3 != 0) {
			s[i].task++;
			s[i].score += (x3 - 1) * 20 + y3;
		}
		if (y4 != 0) {
			s[i].task++;
			s[i].score += (x4 - 1) * 20 + y4;
		}
	}
	sort(s+1,s+n+1,cmp);
	cout << s[1].name << " " << s[1].task << " " << s[1].score;

	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
