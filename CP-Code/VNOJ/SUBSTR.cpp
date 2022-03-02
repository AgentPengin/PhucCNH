#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define fi first
#define se second
#define ll long long
#define EL "\n";
#define time cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n "
#define db(x) do { std::cerr << #x << ": " << x << EL;} while (0)
#define int long long

const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
const int base = 31;
const int mod = 1000000003;
const int NMAX = 1000111;

using namespace std;

string T,P;
int power[NMAX],hashT[NMAX];
int hashP;

int getHash(int i,int j) {
	return (hashT[j] - hashT[i-1] * power[j -i + 1] + mod * mod) % mod;
}

signed main() {
	fastio
	cin >> T >> P;
	int lenT = T.size(),lenP = P.size();
	T = " " + T;
	P = " " + P;
	power[0] = 1;
	for (int i = 1;i<=lenT;i++) {
		power[i] = (power[i-1] * base) % mod;
	}
	for (int i = 1;i<=lenT;i++) {
		hashT[i] = (hashT[i-1] * base+ T[i] - 'a' + 1) % mod;
	} 
	for (int i = 1;i<=lenP;i++) { 
		hashP = (hashP * base + P[i] - 'a' + 1) % mod;
	}
	for (int i = 1;i<=lenT - lenP + 1;i++) {
		if (hashP == getHash(i,i+lenP-1)) cout << i << " ";
	}
	
	
	
	
	
	return 0;
}
// Code cua Phuc ༼ つ ◕_◕ ༽つ
