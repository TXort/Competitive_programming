#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
 
int main() {
	ll n; ll sum = 0;
	scanf("%lld", &n);
	if((((1+n)*n)/2) % 2) {
		printf("NO"); return 0;
	}
	printf("YES\n");
	vector<int> b;
	sum = (((1+n)*n)/2)/2;
	ll x = 0; int z = n;
	do {
		b.push_back(z); x += z; z--;
	} while(x+z<=sum);
	for(int i=1; i<n/2; i++) {
		if(i+x==sum) {
			b.push_back(i); break;
		}
	}
	cout << b.size() << "\n";
	for(int i=0; i<b.size(); i++) printf("%d ", b[i]);
	printf("\n"); cout << n-b.size() << "\n";
	sort(b.begin(),b.end());
	for(int i=1; i<n; i++) {
		if(binary_search(b.begin(),b.end(),i)) continue;
		printf("%d ", i);
	}
	return 0;
}
