#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>

using namespace std;

long long int n;int m; int p[1000010]; int mid; int sol = 0;

int bi(int mid) {
	long long int d = 0;
	for(int i=0;i<n;i++) {
		if(p[i]-mid>0) d+=(p[i]-mid);
	}
	if(d>=m) return 1;
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++) {
		scanf("%d", &p[i]);
	}
	sort(p, p+n);
	int start = 0, end = p[n-1];
	while(start <= end) {
		mid = (start + end) /2;
		if(bi(mid)) {
			start = mid + 1;
			sol = mid;
		}
		else
			end = mid - 1;
	}
	printf("%d", sol);
	return 0;
}
