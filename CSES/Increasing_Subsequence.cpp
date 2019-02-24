#include<iostream>
#include<vector>
 
using namespace std;
 
vector<int> a;
 
int main() {
	int n, x; scanf("%d", &n);
	while(n--) {
		scanf("%d", &x);
		auto it = lower_bound(a.begin(),a.end(),x);
		if (it == a.end()) a.push_back(x);
		else *it = x;
	}
    cout << a.size();
    return 0;
}
