#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n; cin >> n; vector<ll> vll(n+1);
	vector<vector<ll> > f; vector<vector<ll> > s;
	f.insert(f.begin(),n+1,vll); s.insert(s.begin(),n+1,vll);
	for(int i=0;i<n;i++) cin >> f[0][i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n-i;j++) {
			f[i][j] = max(f[0][j] + s[i-1][j+1],f[0][j+i] + s[i-1][j]);
			s[i][j] = f[0][j] + f[i-1][j+1] + s[i-1][j+1] - f[i][j];
		}
	cout << f[n-1][0] << endl;
  	return 0;
 }
