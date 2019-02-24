#include<algorithm>
#include<iostream>
#include<unordered_set>
#include<vector>
#include<cmath>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	int start = 0, end = 0, sol = 1;
	unordered_set<int> s;
	while(end<n) {
		if(s.count(a[end])) {
			sol = max(sol, end - start);
			while (a[start]!=a[end]) s.erase(a[start++]);
			start++;
		} 
		else s.insert(a[end]);
		end++;
	}
	sol = max(sol, end-start);
	cout << sol;
	return 0;
}
