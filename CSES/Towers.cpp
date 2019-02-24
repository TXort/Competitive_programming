#include<iostream>
#include<set>
using namespace std;
 
multiset<int> towers;
 
int main() {
	int n; int x;
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &x);
		auto it = towers.upper_bound(x);
		if(it==towers.end()) {
			towers.insert(x);
		}
		else {
			towers.erase(it);
			towers.insert(x);
		}
	}
	cout << towers.size();
	return 0;
}
