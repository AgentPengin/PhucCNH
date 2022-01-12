#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi first
#define se second
#define ii pair<int,int>
#define N 101
using namespace std;
int a[N];

short s1,s2,s3;
int main() {
	fastio	
	int res;
	memset(a,0,sizeof(a));
	cin >> s1 >> s2 >> s3;
	for (short i = 1;i<=s1;i++) {
		for (short j = 1;j<=s2;j++) {
			for (short k = 1;k<=s3;k++) {
				a[i+j+k]++;
			}
		}
	}
	res = 0;
	for (int i = 0;i<s1+s2+s3;i++) if (a[i]>a[res]) res = i;
 	cout << res;
	return 0;
}
