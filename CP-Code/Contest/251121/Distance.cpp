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
    const int NMAX = 1e5+1;
    ll x,y,max1,max2,min1,min2;

    int main() {
        fastio
        int n;
        max1 = max2 = LONG_MIN;
        min1 = min2 = LONG_MAX;
        cin >> n;
        while(n--) {
            cin >> x >> y;
            max1 = max(max1,x+y); min1 = min(min1,x+y);
            max2 = max(max2,x-y); min2 = min(min2,x-y);
        }
        cout << max(max1-min1,max2-min2);
        return 0;
    }
    // Code cua Phuc ;-;
