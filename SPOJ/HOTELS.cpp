#include<iostream>
#include<vector>
#define ll long long
using namespace std;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	int low = 0, high = 0; ll sum = 0; ll sol = 0;
	while(404) {
		if(high > n-1) break;
		if(a[high]+sum <= x) {
			sum += a[high]; high++;
			}
		else {
			sum -= a[low]; low++;
		}
		if(sum <= x) sol = max(sol, sum);
	}
	cout << sol;
	return 0;
}

