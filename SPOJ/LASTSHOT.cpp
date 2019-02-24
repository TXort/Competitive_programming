#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<algorithm>
#define max_nodes 10005

using namespace std;

vector<vector<int> > adj(max_nodes);
bool visited[max_nodes] = {0};

int impact = 0; int maks = 0;

void dfs(int val) {
	int curr;
	curr = val;
	for(int i=0; i<adj[curr].size();i++) {
		if(visited[adj[curr][i]] == 0) {
			impact++;
			visited[adj[curr][i]] = 1;
			dfs(adj[curr][i]);
		}
	}
}

int main() {
	int v, e; int a, b; int start;
	cin >> v; cin >> e;
	for(int i=0;i<e;i++) {
		cin >> a >> b;
		adj[a].push_back(b);
	}
	for(int i=0;i<v;i++) {
		fill(visited, visited + max_nodes, 0); impact = 1;
		if(visited[i]==0) {
			visited[i] = 1;
			dfs(i);
			if(impact>maks) {
				maks = impact;
			}
		}
	}
	printf("%d", maks);
	return 0;
}

