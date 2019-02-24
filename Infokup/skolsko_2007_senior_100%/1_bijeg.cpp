#include<iostream>

using namespace std;

int memo[20][20];
int dp[20][20];

int recursion(int x, int y) {
   if(x==0 && y==0) return 1;
   if(y<0||x<y) return 0;
   if(memo[x][y]) return dp[x][y];
   memo[x][y] = 1;
   return dp[x][y] = recursion(x-1,y)+recursion(x,y-1);	
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int a, b;
	cin >> a >> b;
	cout << recursion(a,b);
 	return 0;
}

