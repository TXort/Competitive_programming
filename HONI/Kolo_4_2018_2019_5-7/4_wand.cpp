#include<iostream>
#include<vector>

using namespace std;

	vector<vector<int> > g;
	vector<bool> v;

void dfs(int s) {
	for(int u=0;u<g[s].size();u++) {
		if(!v[g[s][u]]) {
			v[g[s][u]] = 1;
			dfs(g[s][u]);
		}
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    vector<int> vi;
    g.insert(g.begin(),n+1,vi);
    v.insert(v.begin(),n+1,0);
    int a, b;
    for(int i=0;i<m;i++) {
    	cin >> b >> a;
    	a--; b--;
    	g[a].push_back(b);
	}
	dfs(0);
	bool ok = 0;
	for(int i=1;i<n;i++) {
		if(v[i]==1) ok = 1;
	}
	if(ok) {
		for(int i=0;i<n;i++) cout << v[i];			
	}
	else {
		cout << 1;
		for(int i=1;i<n;i++) cout << 0;
	}
    return 0;
}
