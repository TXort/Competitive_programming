#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
 
using namespace std;
 
vector<vector<ll> > adj;
vector<ll> visited;
vector<ll> bit;
vector<ll> counter;
vector<ll> val;
vector<ll> dfsarr;
 
ll n;
 
ll sum(int k) {
	ll s = 0;
	while(k>=1) {
		s += bit[k];
		k -= k&-k;
	}
	return s;
}
 
void add(ll k, ll x) {
	while(k<=n) {
		bit[k] += x;
		k += k&-k;
	}
}
 
void dfs2(ll s) {
	if(visited[s]) return;
	visited[s] = 1; dfsarr.push_back(s);
	ll c = 1;
	for(auto u:adj[s]) {
		dfs2(u);
		c += counter[u];
	}
	counter[s] = c;
}
 
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll q;
	cin >> n >> q;
	vector<ll> a;
	vector<ll> sorted(n);
	adj.insert(adj.begin(),n,a);
	val.insert(val.begin(),n,0);
	bit.insert(bit.begin(),n+1,0);
	visited.insert(visited.begin(),n,0);
	counter.insert(counter.begin(),n,0);
	for(int i=0;i<n;i++) cin >> val[i];
	for(int i=0;i<n-1;i++) {
		ll x, y;
		cin >> x >> y;
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	}
	dfs2(0);
	for(int i=0;i<n;i++) sorted[dfsarr[i]] = i;
	for(int i=0;i<n;i++) add(i+1,val[dfsarr[i]]);
		
	while(q--) {
		ll op, loc, x;
		cin >> op;
		if(op==1) {
			cin >> loc >> x; loc--;
			add(sorted[loc]+1, x - val[loc]);
			val[loc] = x;
		}
		else if(op==2) {
			cin >> loc; loc--;
			cout << sum(sorted[loc]+counter[loc]) - sum(sorted[loc]) << "\n";
		}
	}
	return 0;
}
