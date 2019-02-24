#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#define ll long long
 
using namespace std;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n,x,y,z;
	cin >> n;
	vector<tuple<ll,ll,ll> > a(n);
	vector<ll> b(n);
	for(int i=0;i<n;i++) {
		cin >> x >> y >> z;
		a[i] = make_tuple(y,x,z);
	}
	sort(a.begin(),a.end());
	b[0] = get<2>(a[0]);
	for(int i=1;i<n;i++) {
		tie(y,x,z) = a[i];
		ll p = lower_bound(a.begin(),a.end(),make_tuple(x,0,0)) - a.begin() - 1;
		ll m = b[i-1];
		if(p>=0) m = max(m, b[p]+z);
		else m = max(m, z);
		b[i] = m;
	}
	cout << b[n-1];
	return 0;
}
