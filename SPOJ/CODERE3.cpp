#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main() {
	int n, x, t, sol;
	scanf("%d", &t);
	while(t--) {
		sol = 0;
		scanf("%d", &n);
		vector<int> inp(n);
		vector<int> dp1(n, 1);
		vector<int> dp2(n, 1);
		for(int i=0;i<n;i++) scanf("%d", &inp[i]);
		
		for(int k=1;k<n;k++) {
			for(int i=0;i<k;i++) {
				if(inp[i]<inp[k])
					dp1[k] = max(dp1[k], dp1[i]+1);
			}
		}
		for(int k=n-2;k>=0;k--) {
			for(int i=n-1;i>k;i--) {
				if(inp[i]<inp[k])
					dp2[k] = max(dp2[k], dp2[i]+1);
			}
		}
		int sol = 0;
		for(int i=0;i<n;i++) {
			sol = max(sol, dp1[i]+dp2[i] - 1);
		}
		printf("%d\n", sol);
	}
	return 0;
}

