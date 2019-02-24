#include<iostream>
 
int p(int x, int n, int m) {
	if(n==0) return 1%m;
	long long u = p(x,n/2,m);
	u = (u*u)%m;
	if(n%2==1) u = (u*x)%m;
	return u;	
}

int main() {
	int n,a,b,sol;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &a,&b);
		sol = p(a,b,1000000007);
		printf("%d\n", sol);
	}
	return 0;
}
