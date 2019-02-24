#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
     
using namespace std;
     
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    sort(a.begin(),a.end()); sort(b.begin(),b.end());
    if(n>m) swap(a,b);
    int low = -1, high = 1e9, mid, t;
    bool valid;
    while(high-low>1) {
    	mid = (low+high)>>1;
    	t = 0; valid = 1;
    	for(int i=0;i<a.size();i++) {
    		if(t>=b.size()) {
    			valid = 0;
    			break;
    		}
    		while(t<b.size() && b[t]<=a[i] && a[i]-b[t]>mid) t++;
    		if(t>=b.size() || abs(a[i]-b[t])>mid) {
    			valid = 0;
    			break;
    		}
    		t++;
    	}
    	if(valid) high = mid;
    	else low = mid;
    }
    cout << high;
    return 0;
}
