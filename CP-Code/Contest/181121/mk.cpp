#include<iostream>
#include<iomanip>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<vector>
#include<utility>
#include<set>
#include<queue>
#include <chrono>
#include<map>

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> bigNum;
typedef  vector<vector<int>> vii;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
#define fi first
#define se second 
#define pb push_back
#define EL "\n"
#define FOR(i,a,b) for (int i = a;i<=b;i++) 
#define DEC(i,a,b) for (int i = a;i>=b;i--)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b))*b
#define time_start() auto start = chrono::steady_clock::now(); 
#define time_end() auto end = chrono::steady_clock::now();
#define time_use() cout << EL << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

map<string,int> cnt,s;
string l[20001];
int n;

int main() {
    fastio
    cin >> n;
    for (int i = 0;i<n;i++) {
        cin >> l[i];
        s.clear();
        for (int j = 0;j<l[i].size();j++) {
            string curr;
            for (int k = j;k<l[i].size();k++) {
                curr.push_back(l[i][k]);
                s[curr]++;
            }
        }
        for (auto x : s) {
            cnt[x.fi]++;
        }
    }
    int res = 0;
    for (auto x : l) {
        res += cnt[x];
    }
    cout << res - n;
    return 0;
}
// Code cua Phuc ;-;
