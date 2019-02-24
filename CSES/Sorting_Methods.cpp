#include<iostream>
#include<algorithm>
#include<vector>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
#include<functional>
#define ll long long
#define MAX 200005
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
int n;
int arr[MAX];
pair<int,int> arrp[MAX];
bool v[MAX];
vector<int> sub;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ordered_set o;
	cin >> n;
	ll sol1 = 0, sol2 = 0, sol3 = 0, sol4 = n;
	for(int i=0;i<n;i++) cin >> arr[i];
	for(int i=0;i<n;i++) {
		o.insert(arr[n-i-1]);
		sol1 += o.order_of_key(arr[n-i-1]);
	}
    for(int i=0;i<n;i++) { 
        arrp[i].first = arr[i]; 
        arrp[i].second = i; 
    } 	
	sort(arrp,arrp+n); 	
    for(int i=0;i<n;i++) { 
        if (v[i] || arrp[i].second == i) continue; 
        int c = 0; 
        int j = i; 
        while (!v[j]) { 
            v[j] = 1; 
            j = arrp[j].second; 
            c++; 
        } 
        if(c>0) sol2+=(c-1); 
    } 	
    for(int i=0;i<n;i++) { 
        auto it = lower_bound(sub.begin(),sub.end(),arr[i]);
		if(it==sub.end()) sub.push_back(arr[i]);
		else *it = arr[i];        
    } 
    sol3 = n - sub.size();
    for(int i=n-1;i>=0;i--) if (arr[i]==sol4) sol4--; 
	cout << sol1 << " " << sol2 << " " << sol3 << " " << sol4;
	return 0;
}
