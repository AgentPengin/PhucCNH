#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);

using namespace std;

struct average{
	int val,i,j;
};

int n;
int a[1001];
vector<average> arr;

bool check(int ax) {
    for (int i = 1;i<=n;i++) {
    	int ag = ax - a[i];
    	int ans = -1;
    	int left = 0,right = (int)arr.size() - 1;
    	while(left <= right) {
    		int mid = (left + right)/2;
    		if (arr[mid].val >= ag) {
    			right = mid - 1;
    			if (arr[mid].val == ag) ans = mid;
    		} else left = mid + 1;
    	}
    	if (ans != -1) {
    		for (int j = ans;j<arr.size();j++) {
    			if (arr[j].val > ag) break;
    			if (arr[j].i != i && arr[j].j != i) {
    				return true;
    			}
    		}
    	}
    	
    	
    }
	return false;
	
	
}

signed main() {
	fastio
	cin >> n;
	for (int i = 1;i<=n;i++) cin >> a[i];
	for (int i = 1;i<=n-1;i++) {
		for (int j = i+1;j<=n;j++) arr.push_back({a[i] + a[j],i,j});
	}
	sort(arr.begin(),arr.end(),[](average &ax,average bx) {
		return ax.val < bx.val;
	});
	int res = 0;
	for (int i = 1;i<=n;i++) {
		if (check(3*a[i])) res++;
	}
	cout << res;
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
