#include<iostream>
#include<vector>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#include<functional>
 
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
	int median = 0;
	if(k%2) median = k/2;
	else median = k/2-1;
	cout << *(o.find_by_order(median)) << ' ';
	for(int i=0;i<(n-k);i++) {
		o.erase(o.find_by_order(o.order_of_key(a[i])));
		o.insert(a[i+k]);
		cout << *(o.find_by_order(median)) << ' ';
	}
    return 0;
}
