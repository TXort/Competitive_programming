#include<iostream>
#include<vector>
#define ll long long
 
using namespace std;
const int mod = 1000000007;
 
ll expo(ll expo, int n, int x) {
    ll rj = 1;
    while(n) {
        if(n&1) rj = (rj*expo)%x;
        expo = (expo*expo)%x;
        n>>=1;
    }
    return rj;
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    int n, sum = 0;
    cin >> n;
    sum = (n*(n+1))/2;
    if(sum&1) {
        cout << 0 << "\n"; return 0;
    }
    sum /= 2;
    vector<int> dp(sum+1, 0);
    dp[0] = 1;
    for(int i=0;i<n;i++) 
        for(int j=sum;j>=0;j--)
            if(j+i+1<=sum)
                dp[j+i+1]=(dp[j+i+1]+dp[j])%mod;
    cout << (dp[sum]*expo(2,mod-2,mod))%mod << "\n";
    return 0;
}
