#include<iostream>
#include<algorithm>
 
int a[500005];
 
int main() {
	int n,x;
	scanf("%d %d", &n, &x);
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	int start = 0, end = n-1, sol = 0;
	std::sort(a, a+n);
	while(start<=end) {
		if(a[start]+a[end]>x) end--;
		else {
			start++; end--;
		}
		sol++;
	}
	printf("%d", sol);
	return 0;
}
