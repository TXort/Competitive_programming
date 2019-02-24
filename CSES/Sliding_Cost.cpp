#include<iostream>
#include<vector>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#include<functional>
#define ll long long
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n, k;
	ordered_set o;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<k;i++) o.insert(a[i]);
	ll median = 0, cost = 0, new_cost = 0, left, right;
	if(k%2) median = k / 2;
	else median = k / 2 - 1;
	int median_value = *(o.find_by_order(median));
	for(int i=0;i<k;i++) cost += abs(a[i]-median_value);
	ll old_median = median_value;
	cout << cost << ' ';
	for(int i=0;i<(n-k);i++) {
		o.erase(o.find_by_order(o.order_of_key(a[i])));
		o.insert(a[i+k]);
		median_value = *(o.find_by_order(median));
		left = a[i]; right = a[i+k];
		new_cost = cost - (abs(old_median-left)) + (abs(median_value-right));
		if(k%2==0) new_cost -= (median_value - old_median);
		cout << new_cost << ' ';
		cost = new_cost; old_median = median_value;
	}
    return 0;
}
