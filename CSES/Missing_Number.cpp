#include<iostream>
#include<algorithm>
using namespace std;

int a[500003];

int main() {
	int n;
	scanf("%d", &n); n--;
	for(int i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	for(int i=0;i<n;i++) {
		if(a[i]!=i+1) {
			printf("%d", i+1);
			return 0;
		}
	}
	return 0;
}
