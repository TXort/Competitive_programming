#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

int mak3(int a, int b, int c) {
   return max(a, max(b,c));
}

int dpp[101][101];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,m; short t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> dpp[i][j];
		vector<int> dp(m), dpprosli(m);
		for(int i=0;i<m;i++) dp[i] = dpp[n-1][i];
		vector<int> v(m);
  		for(int i=n-2;i>=0;i--) {
     		dpprosli = dp;
     		for(int j=0;j<m;j++) v[j] = dpp[i][j];
     		dp[0] = max(dpprosli[0],dpprosli[1]) + v[0];
     		for(int j=1;j<m;j++) {
     			if(j==m-1) dp[j] = max(dpprosli[j], dpprosli[j-1]) + v[j];
				else dp[j] = mak3(dpprosli[j], dpprosli[j-1],dpprosli[j+1]) + v[j];
     		}
  		}
  		memset(dpp, 0, sizeof(dpp));
  		int sol = 0;
  		for(int i=0;i<m;i++) sol = max(sol, dp[i]);
  		cout << sol << "\n";
  	}
  	return 0;
}

