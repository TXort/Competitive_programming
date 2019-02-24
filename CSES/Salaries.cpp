#include<iostream>
#include<vector>
#include<cmath>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#include<functional>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n, q, a, b;
	char c;
	int polje[200004];
	ordered_set o;
	cin >> n >> q;
	for(int i=0;i<n;i++) {
		cin >> polje[i];
		o.insert(polje[i]);
	}
	for(int i=0;i<q;i++) {
		cin >> c;
		if(c=='?') {
			cin >> a >> b;
			cout << (o.order_of_key(b+1)-o.order_of_key(a)) << "\n";
		}
		if(c=='!') {
			cin >> a >> b;
			o.erase(o.find_by_order(o.order_of_key(polje[a-1])));
			polje[a-1] = b;
			o.insert(b);
		}
	}
    return 0;
}
