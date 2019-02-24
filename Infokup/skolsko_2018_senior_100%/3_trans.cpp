#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<set>

using namespace std;

queue<pair<int,vector<int> > > q;
set<vector<int> > s;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n; cin >> n;
	vector<int> start(n);
	vector<int> end(n);
	for(int i=0;i<n;i++) cin >> start[i];
	for(int i=0;i<n;i++) cin >> end[i];
	q.push(make_pair(0,start));
	s.insert(start);
	int sol, ss; vector<int> z, p;
	while(!q.empty()) {
		sol = q.front().first; z = q.front().second; q.pop();
		if(z == end) {
			cout << sol;
			return 0;
		}
		p = z;
		for(int i=2;i<=n+1;i++) {
			z = p;
			for(int j=0;j<z.size();j++) if(i>z[j]) z[j] = abs(i-z[j]);
			if(s.find(z)==s.end()) {
				s.insert(z);
				q.push(make_pair(sol+1,z));
			}
		}
	}
	return 0;
}
