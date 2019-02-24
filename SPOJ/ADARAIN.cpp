#include<stdio.h>

int area[1000001] = {0}; int dif[1000001] = {0};
int n, q, s; int l, r; int i = 1;

int main() {
	scanf("%d %d %d", &n, &q, &s);
	while(n--) {
		scanf("%d %d", &l, &r);
		dif[l] += 1;
		dif[r+1] -= 1;
	}
	area[0] = dif[0];
	for(;i<=s;i++) area[i] = area[i-1] + dif[i];
	while(q--) {
		int index;
		scanf("%d", &index);
		printf("%d\n", area[index]);
	}
	return 0;
}

