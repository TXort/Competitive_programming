#include<iostream>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

int dp[2001][2001];

string s1; string s2;

int min3(int a, int b, int c) {
	return (min(a, min(b, c)));
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	short test; cin >> test;
	while(test--) {
		cin >> s1 >> s2;
		for(int i=0;i<s1.size()+1;i++) dp[i][0] = i;
		for(int i=0;i<s2.size()+1;i++) dp[0][i] = i;
		for(int i=1;i<s1.size()+1;i++)
			for(int j=1;j<s2.size()+1;j++) {
				if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
				else dp[i][j] = min3(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1;
			}
		cout << dp[s1.size()][s2.size()] << "\n";
		for(int i=0;i<s1.size();i++) for(int j=0;j<s2.size();j++) dp[i][j] = 0;
	}
	return 0;
}

