#include<iostream>
#include<vector>
#define N 200040
 
using namespace std;
 
vector<int> adj[N+5];
bool visited[N+5];
int Euler[4*N];
int depth_arr[4*N];
int extendedarr[4*N];
int tree[8*N];
 
void build(int n, int b, int e) {
 	if (b>e) return;
 	else if (b==e) {
  		tree[n]= depth_arr[b];
  		return;
 	}
 	build(n*2,b,(b+e)/2); 
	build(n*2+1,(b+e)/2+1,e);
	tree[n] = min(tree[n*2],tree[n*2+1]);
}
 
int query(int n, int b, int e, int i, int j) {
	if (i>e || b>j) return 1000000000;
 	if (b==i && e==j) return tree[n];
 	int mid = (b+e)/2;
 	if(j<=mid) return query(n*2,b,mid,i,j);
 	if(i>mid) return query(n*2+1,mid+1,e,i,j);
 	return min(query(n*2,b,mid,i,mid),query(n*2+1,mid+1,e,mid+1,j));
}
 
int index;
 
void dfs(int node,int depth)  { 
    visited[node] = 1; 
    index++;
    Euler[index] = node;
    depth_arr[index] = depth;
    for(auto u : adj[node]) { 
        if(!visited[u]) { 
            dfs(u, depth+1);
            index++;
            Euler[index] = node;
            depth_arr[index] = depth;
        } 
    } 
}
  
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n, q;
	cin >> n >> q;
	for(int i=0;i<n-1;i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,1);
	build(1,0,2*n-1);
	for(int i=1;i<n*2;i++) extendedarr[Euler[i]] = i;
	int a, b;
	while(q--) {
		cin >> a >> b;
		int l = extendedarr[a];
		int h = extendedarr[b];
		if(l>h) swap(l,h);
		cout << (depth_arr[l] + depth_arr[h]) - (2*(query(1,0,2*n-1,l,h)));
		cout << "\n";
	}
	return 0;
}
