#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
 
 
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<long long> a(n);
	long long int low = 0, high = 0;
	for(int i=0;i<n;i++) {
		scanf("%d", &a[i]);
		high += a[i];
		low = max(a[i], low);
	}
	while(low<high) {
		long long int mid = (low+high)/2;
		long long int part_sum = 0;
		int parts = 1;
		for(int i=0;i<n;i++) {
			part_sum += a[i];
			if(part_sum>mid) {
				part_sum = a[i]; parts++;
			}
		}
		if(parts<=k) high = mid;
		else low = mid + 1;
	}
	printf("%lld", low);
	return 0;
}
	
