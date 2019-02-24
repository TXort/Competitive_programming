#include<iostream>
#include<vector>
 
using namespace std;
 
int predznak(int n) {return n<0?1:0;}

int main() {
	int n, x, sol;
	sol = 0;
	scanf("%d", &n);
	vector<int> inp(n);
	vector<int> dp1(n, 1);
	for(int i=0;i<n;i++) scanf("%d", &inp[i]);
		
	for(int k=1;k<n;k++)
		for(int i=0;i<k;i++)
			if(abs(inp[i])<abs(inp[k]) && predznak(inp[i])!=predznak(inp[k]))
				dp1[k] = max(dp1[k], dp1[i]+1);
	
	for(int i=0;i<n;i++) sol = max(sol, dp1[i]);
	
	printf("%d", sol);
	return 0;
}

