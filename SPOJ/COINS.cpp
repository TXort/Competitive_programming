#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#define ll long long

using namespace std;

map<int, long long> dp;

ll solve(int n) {
	if(n==0) return 0;
	if(dp[n]!=0) return dp[n];
	ll rec = solve(floor(n/2)) + solve(floor(n/3)) + solve(floor(n/4));
	if(rec>n) dp[n] = rec;
	else dp[n] = n;
	return dp[n];
}

int main() {
	int n;
	while( scanf("%d",&n)!=EOF ) {
		printf("%lld\n", solve(n));
	}
 	return 0;
}

