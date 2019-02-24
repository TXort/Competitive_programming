#include<iostream>
#include<cstring>
#define inf 100000000

using namespace std;

int dp[1003][1003];
int o[1001], nit[1001], wei[1001];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n, m, x, y; cin >> n;
	while(n--) {
		cin >> x >> y >> m;
		for(int i=0;i<=1000;i++)
			for(int j=0;j<=1000;j++)
				dp[i][j] = inf;
		for(int i=0;i<m;i++) cin >> o[i] >> nit[i] >> wei[i];	
		dp[0][0] = 0;
		for(int c=0;c<m;c++)
			for(int i=4*x; i>=0; i--)
				for(int j=4*y; j>=0; j--)
					if(dp[i][j]<inf)
						dp[i+o[c]][j+nit[c]] = min(dp[i][j]+wei[c], dp[i+o[c]][j+nit[c]]);
		int sol = inf;
		for(int i=x;i<=1000;i++)
			for(int j=y;j<=1000;j++)
				sol = min(sol, dp[i][j]);
		cout << sol << "\n";
		memset(o, 0, sizeof o);
		memset(nit, 0, sizeof nit);
		memset(wei, 0, sizeof wei);
	}
	return 0;
}
