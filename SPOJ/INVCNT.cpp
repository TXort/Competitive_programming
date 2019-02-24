#include<iostream>
#include<algorithm>
#include<vector>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#include<functional>
#define ll long long
#define M 200005

using namespace __gnu_pbds;
using namespace std;
 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
int n, t;
int z[M];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> t;
	while(t--) {
		ordered_set o;
		cin >> n;
		ll q = 0;
		for(int i=0;i<n;i++) cin >> z[i];
		for(int i=0;i<n;i++) {
			o.insert(z[n-i-1]);
			q += o.order_of_key(z[n-i-1]);
		}
	cout << q << "\n";			
	}
	return 0;
}

