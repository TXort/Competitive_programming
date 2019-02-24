#include<iostream>
#include<vector>
#define inf 1000000

using namespace std;

char parking[1001];
int prefsum[1001];
int p, k, l;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> p >> k >> l;
	for(int i=0;i<p;i++) cin >> parking[i];
	prefsum[0] = (parking[0]=='#'?1:0);
	for(int i=1;i<p;i++) prefsum[i] = prefsum[i-1] + (parking[i]=='#'?1:0);
	vector<int> dp1(p+1);
	vector<int> dp2(p+1);
	for(int i=0;i<p;i++) {
		if(i-l+1<0) dp2[i] = inf;
		else dp2[i] = min(prefsum[p-i+l-2] - prefsum[p-i-2],dp2[i-1]);
	}
	for(int kam=1;kam<k;kam++) {
		for(int i=0;i<p;i++) {
			if(i-l*(kam+1)+1<0) dp1[i] = inf;
			else dp1[i] = min(prefsum[p-i+l-2]-prefsum[p-i-2]+dp2[i-l],dp1[i-1]);
		}
		dp2 = dp1;
	}
	cout << dp2[p-1];
	return 0;
}
