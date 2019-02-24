#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#define ll long long

using namespace std;

ll prefsum[1000005];
vector<pair<int,int> > bprints_h;
vector<pair<int,int> > bprints_w;
map<pair<int,int>,int> M;
map<int,pair<int,int>> used;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n, k, w, h;
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		cin >> w >> h;
		bprints_h.push_back(make_pair(h,w));
		bprints_w.push_back(make_pair(w,h));
	}
	sort(bprints_h.begin(),bprints_h.end(),greater<pair<int,int> >());
	sort(bprints_w.begin(),bprints_w.end());
	M.insert(make_pair(make_pair(bprints_w[0].first, bprints_w[0].second),0));
	prefsum[0] =  bprints_w[0].first;
	for(int i=1;i<n;i++) {
		M.insert(make_pair(make_pair(bprints_w[i].first, bprints_w[i].second),i));
		prefsum[i] = prefsum[i-1] + bprints_w[i].first;
	}
	int index, i=0; 
	ll diff = 0, sum = 0, sol = 1000000000000000000;
	while(n>=k) {
		index = M.find(make_pair(bprints_h[i].second,bprints_h[i].first))->second;
		sum = prefsum[k-1];
		sum -= diff;
		sol = min(sol, bprints_h[i].first*sum);
		if(index>k) used.insert(make_pair(index,make_pair(bprints_h[i].second,bprints_h[i].first)));
		if(index<=k) {
			k++; diff += bprints_h[i].second;
			while(used.find(k)!=used.end()) {
				diff += (used.find(k)->second.first);
				k++;
			}
		}
		i++;
	}
	cout << sol;
	return 0;
}
