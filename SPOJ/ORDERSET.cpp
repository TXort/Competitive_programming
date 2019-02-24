#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#include<functional>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ordered_set o;
	int t; cin >> t;
	char c; int n;
	while(t--) {
		cin >> c >> n;
		if(c=='I') o.insert(n);
		else if(c=='D') o.erase(n);
		else if(c=='C') cout << o.order_of_key(n) << "\n";
		else {
			if(n>o.size()) cout << "invalid\n";
            else cout << *o.find_by_order(n - 1) << "\n";
		}
	}
    return 0;
}

