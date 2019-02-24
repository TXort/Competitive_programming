#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#define max_nodes 10005

using namespace std;

vector<vector<int> > adj(max_nodes);
bool visited[max_nodes] = {0};
void dfs(int val) {
	int curr;
	curr = val;
//	cout << curr << " ";
	for(int i=0; i<adj[curr].size();i++) {
		if(visited[adj[curr][i]] == 0) {
			visited[adj[curr][i]] = 1;
			dfs(adj[curr][i]);
		}
	}
}
int main()
{
	int v, e; int a, b; int start;
	cin >> v; cin >> e;
	cin >> a >> b; start = a;
	adj[a].push_back(b);
	adj[b].push_back(a);
	for(int i=0;i<e-1;i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if(e!=v-1) {
		printf("NO");
		return 0;
	}
	visited[start]=1; dfs(start);

	for(int i=start;i<v;i++) {
		if(visited[i]==0) {
			printf("NO");
			return 0;
	} }
	printf("YES");
	return 0;
}
