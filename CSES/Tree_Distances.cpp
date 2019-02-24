#include<iostream>
#include<cstring>
#include<vector>
#define N 500000
 
using namespace std;
 
vector<int> adj[N];
bool visited[N];
int dfa[N]; int dfb[N];
 
int maxdist, fn;
 
void dfs1(int dist, int node) {
	if(visited[node]) return;
	visited[node] = 1;
	if(dist>maxdist) {
		maxdist = dist; fn = node;
	}
	for(auto u:adj[node]) {
		if(!visited[u]) dfs1(dist+1,u);
	}	
}
 
void dfs2(int dist, int node) {
	if(visited[node]) return;
	visited[node] = 1;
	if(dist>=maxdist) {
		maxdist = dist; fn = node;
	}
	dfa[node] = dist;
	for(auto u:adj[node]) {
		if(!visited[u]) dfs2(dist+1,u);
	}	
}
 
void dfs3(int dist, int node) {
	if(visited[node]) return;
	visited[node] = 1;
	dfb[node] = dist;
	for(auto u:adj[node]) {
		if(!visited[u]) dfs3(dist+1,u);
	}	
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,a,b; cin >> n;
	for(int i=0;i<n-1;i++) {
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	int firstnode;
	dfs1(0,0);
	memset(visited,0, sizeof(visited));
	dfs2(0,fn);
	memset(visited,0, sizeof(visited));
	dfs3(0,fn);
	for(int i=0;i<n;i++) cout << max(dfa[i],dfb[i]) << " ";
	return 0;
}
