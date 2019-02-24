#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
 
using namespace std;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,x,l,f,s;
	cin >> n >> x;
	set<pair<int,int> > a;
	set<pair<int,int> > b;
	a.insert(make_pair(n,n));
	b.insert(make_pair(n,n));
	for(int i=0;i<x;i++) {
		cin >> l;
		auto it = a.lower_bound({l,0});
		f = it->first; s = it->second;
		a.insert(make_pair(l, s - (f - l)));
		a.insert(make_pair(f, f-l));
		b.erase(make_pair(s,f));
		b.insert(make_pair(s - (f - l), l));
		b.insert(make_pair(f-l,f));
		cout << get<0>(*b.rbegin()) << " ";
	}
    return 0;
}
