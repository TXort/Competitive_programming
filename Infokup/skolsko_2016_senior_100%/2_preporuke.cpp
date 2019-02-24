#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

map <string,int> M;
map <int,string> Mr;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n; cin >> n; n--;
	int m; cin >> m;
	vector<int> mirko;
	string s; int id = 0;
	for(int i=0;i<m;i++) {
		cin >> s;
		if(M.find(s)==M.end()) {
			M.insert({s,id});
			mirko.push_back(id);
			id++;
		}
	}
	vector<vector<int> > movies(n);
	for(int i=0;i<n;i++) {
		cin >> m; 
		while(m--) {
			cin >> s;
			if(M.find(s)==M.end()) {
				M.insert({s,id});
				id++;
			}
			auto it = M.find(s);
			movies[i].push_back(it->second);
		}
		sort(movies[i].begin(),movies[i].end());
	}
	vector<int> common(n);
	int maks = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<mirko.size();j++) {
			if(binary_search(movies[i].begin(),movies[i].end(),mirko[j])) {
				auto it = lower_bound(movies[i].begin(),movies[i].end(),mirko[j]);
				movies[i].erase(it);
				common[i]++;
				maks = max(maks, common[i]);
			}
		}
	}
	for (auto i=M.begin(); i!=M.end(); i++) Mr[i->second] = i->first;
	set<string> sol;
	for(int i=0;i<n;i++) {
		if(common[i]==maks) {
			for(int j=0;j<movies[i].size();j++) {
				sol.insert((Mr.find(movies[i][j]))->second);
			}
		}
	}
	for(auto x:sol) cout << x << " ";
	return 0;
}
