#include<iostream>
#define ll long long
#define N 1000000
 
using namespace std;
 
const ll mod = 1000000007;
long long factorial[N];
 
ll p(int x, int n, int m) {
	if(n==0) return 1%m;
	long long u = p(x,n/2,m);
	u = (u*u)%m;
	if(n%2==1) u = (u*x)%m;
	return u;	
}
 
ll mi(ll n, ll MOD) {return p(n,MOD-2,MOD);}
 
void tab(long long z) {
    factorial[0] = 1;
    for(int i=1;i<z;i++) factorial[i] = factorial[i-1]*i%mod;
}
 
ll solve(ll n, ll r, ll MOD) {return (factorial[n]*((mi(factorial[r], MOD) * mi(factorial[n-r], MOD)) % MOD)) % MOD;}
 
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
 	int t,a,b; cin >> t;
  	tab(N);
  	while(t--) {
     	cin >> a >> b;
     	cout << solve(a,b,mod) << "\n";
  	}
 	 return 0;
}
