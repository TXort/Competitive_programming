#include<iostream>
#include<algorithm>
#include<tuple>
#include<vector>

using namespace std;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		int we = b - a;
		vector<int> dp(we+1,1000000000);
		int n; cin >> n;
		vector<int> val(n);
		vector<int> wt(n);
		for(int i=0;i<n;i++)
			cin >> val[i] >> wt[i];
		dp[0] = 0;
		for(int i=0;i<=we;i++)
			for(int j=0;j<n;j++)
				if(wt[j]<=i)
					dp[i] = min(dp[i],dp[i-wt[j]]+val[j]);
		if(dp[we]!=1000000000) cout << "The minimum amount of money in the piggy-bank is " << dp[we] << ".";
		else cout << "This is impossible.";
		cout << "\n";
	}
	return 0;
}

