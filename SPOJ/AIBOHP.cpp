#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

int dp[6101][6101];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		string rs = s; reverse(rs.begin(),rs.end());
		for(int i=1;i<=s.size();i++)
			for(int j=1;j<=rs.size();j++)
				if(s[i-1]==rs[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
				else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		cout << s.size() - dp[s.size()][rs.size()] << "\n";
		memset(dp, 0, sizeof(dp));		
	}
	return 0;
}

