#include<iostream>
 
using namespace std;
 
int n, x, h[1002], s[1002], dp[1002][100002];
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
 	cin >> n >> x;
  	for (int i = 1; i <= n; ++i) cin >> h[i];
  	for (int i = 1; i <= n; ++i) cin >> s[i];
 	for (int i=1;i<=n;++i)
    	for (int j=1;j<=x;++j) {
      		if(j>=h[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-h[i]] + s[i]);
      		else dp[i][j] = dp[i-1][j];
	}
  	cout << dp[n][x];
  return 0;
}
