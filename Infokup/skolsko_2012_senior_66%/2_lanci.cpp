#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n; cin >> n;
	vector<int> arr(n);
	vector<int> prefsum(n);
	for(int i=0;i<n;i++) cin >> arr[i];
	prefsum[0]=arr[0];
	for(int i=1;i<n;i++) prefsum[i] = arr[i] + prefsum[i-1];
	int sol = 2000000000;
	int left_sum, right_sum;
	for(int i=1;i<n-1;i++) {
		left_sum = prefsum[i-1];
		right_sum = prefsum[n-1]-prefsum[i];
		sol = min(sol, abs(right_sum-left_sum));
	}
	cout << sol;
	return 0;
}
