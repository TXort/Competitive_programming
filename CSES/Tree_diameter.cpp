#include<iostream>
#include<cstring>
#include<vector>
#define N 500000
 
using namespace std;
 
vector<int> adj[N];
bool visited[N];
 
int maxdist, fn;
 
void dfs(int dist, int node) {
	if(visited[node]) return;
	visited[node] = 1;
	if(dist>maxdist) {
		maxdist = dist; fn = node;
	}
	for(auto u:adj[node]) {
		if(!visited[u]) dfs(dist+1,u);
	}	
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n, a, b; cin >> n;
	for(int i=0;i<n-1;i++) {
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	int distance, firstnode;
	dfs(0,0);
	distance = maxdist; firstnode = fn;
	memset(visited,0, sizeof(visited));
	dfs(0,fn);
	cout << max(maxdist, distance);
	return 0;
}
