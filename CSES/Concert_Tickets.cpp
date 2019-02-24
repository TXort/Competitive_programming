#include<iostream>
#include<vector>
#include<algorithm>
#include<set> 
using namespace std;
 
int main() {
	int n, m, x;
	scanf("%d %d", &n, &m);
	multiset<int> tickets;
	while(n--) {
		scanf("%d", &x);
		tickets.insert(x);
	}
	while(m--) {
		scanf("%d", &x);
		auto it = tickets.lower_bound(x);
		if(it==tickets.begin() and *it>x) printf("-1\n");
		else if(*it==x) {
			printf("%d\n", *it);
			tickets.erase(it);
		}
		else {
			if(it!=tickets.begin()) it--;
			printf("%d\n", *it);
			tickets.erase(it);			
		}
	}
	return 0;
}
