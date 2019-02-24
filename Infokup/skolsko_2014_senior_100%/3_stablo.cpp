#include<iostream>
#include<queue>
#include<list>

using namespace std;

list<int> adj[25];
bool visited[25];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n; cin >> n;
	for(int i=1;i<=n;i++) {
		int x, y;
		cin >> x >> y;
		if(x) adj[i].push_front(x);
		if(y) adj[i].push_front(y);
	}
	visited[1] = true;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int s = q.front(); q.pop();
		cout << s << " ";
		for(auto u : adj[s]) {
			if(visited[u]) continue;
			visited[u] = true;
			q.push(u);
		}
	}
	return 0;
}
