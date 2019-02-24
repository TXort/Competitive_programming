#include<iostream>
#include<utility>
#include<vector>
#define ll long long

using namespace std;

int main()
{
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	for(int test=0;test<t;test++) {
		int n, x; cin >> n;
		if(n==0) {
			cout << "Case " << test+1 << ": " << 0 << "\n"; continue;
		}
		vector<ll> a(n,0);
		vector<ll> dp(n,0);
		for(int i=0;i<n;i++) cin >> a[i];
		dp[0] = a[0]; dp[1] = max(a[0],a[1]);
		for(int i=2;i<n;i++) dp[i] = max(dp[i-2]+a[i],dp[i-1]);
		cout << "Case " << test+1 << ": " << dp[n-1] << "\n";
	}
	return 0;
}

