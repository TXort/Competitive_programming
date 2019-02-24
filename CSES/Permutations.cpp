#include<iostream>
 
int main() {
	int n; int x = 1;
	scanf("%d", &n);
	if(n<4 and n!=1) {
		printf("NO SOLUTION");
		return 0;
	}
	if(n==4) {
		printf("2 4 1 3");
		return 0;
	}
	for(int i=0;i<n/2+(n%2);i++) {
		printf("%d ", x);
		x += 2;
	}
	x = 2;
	for(int i=0;i<n/2;i++) {
		printf("%d ", x);
		x += 2;
	}
	return 0;
}
