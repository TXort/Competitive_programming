#include<iostream>
#define ll long long

using namespace std;

int main()
{
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t = 1, test = 1;
	while(t) {
		cin >> t;
		if(!t) break;
		ll c0, c1, c2;
		ll dp0, dp1, dp2;
		ll dpp0, dpp1, dpp2;
		cin >> c0 >> c1 >> c2;
		dpp0 = c0; dpp1 = c1; dpp2 = c1+c2;
		cin >> c0 >> c1 >> c2;
		dp0 = dpp1+c0;
		dp1 = c1 + min(dp0,min(dpp1,dpp2));
		dp2 = c2 + min(dp1,min(dpp1,dpp2));
		for(int i=0;i<t-2;i++) {
			dpp0 = dp0; dpp1 = dp1; dpp2 = dp2;
			cin >> c0 >> c1 >> c2;
			dp0 = c0 + min(dpp0,dpp1);
			dp1 = c1 + min(dpp0, min(dpp1,min(dpp2,dp0)));
			dp2 = c2 + min(dp2, min(dpp1,dp1));	
		}
		cout << test << ". " << dp1 << "\n";
		test++;
	}
	return 0;
}
