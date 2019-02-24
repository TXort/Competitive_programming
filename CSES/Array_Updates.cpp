#include<iostream>
#include<vector>
#include<cmath>
#define ll long long
#define MAX 200005
 
using namespace std;
 
struct node{
	ll ls;
	ll rs;
	ll ts;
	ll bs;
}tree[MAX*4];
 
ll arr[MAX];
 
ll mak3(ll a, ll b, ll c) {return max(a, max(b, c));}
 
void build(ll n, ll b, ll e)
{
 	if (b>e) return;
 	else if (b==e) {
  		tree[n].ls = arr[b];
  		tree[n].rs = arr[b];
  		tree[n].ts = arr[b];
		tree[n].bs = arr[b];
  		return;
 	}
 	build(n*2,b,(b+e)/2); 
	build(n*2+1,(b+e)/2+1,e);
	tree[n].ls = mak3(tree[n*2].ls, tree[n*2].ts, tree[n*2].ts+tree[n*2+1].ls);
	tree[n].rs = mak3(tree[n*2+1].rs, tree[n*2+1].ts, tree[n*2+1].ts+tree[n*2].rs);
	tree[n].ts = tree[n*2].ts + tree[n*2+1].ts;
	tree[n].bs = mak3(tree[n*2].bs, tree[n*2+1].bs, tree[n*2].rs+tree[n*2+1].ls);
}
 
void update(ll n, ll b, ll e, ll idx, ll val) {
 	if (b>e || b>idx || e<idx) return;
 	if (b==e) {
  		tree[n].ls = val;
  		tree[n].rs = val;
  		tree[n].ts = val;
  		tree[n].bs = val;
  		return;
 	}
 	update(n*2,b,(b+e)/2,idx,val);
 	update(n*2+1,(b+e)/2+1,e,idx,val);
	tree[n].ls = mak3(tree[n*2].ls, tree[n*2].ts, tree[n*2].ts+tree[n*2+1].ls);
	tree[n].rs = mak3(tree[n*2+1].rs, tree[n*2+1].ts, tree[n*2+1].ts+tree[n*2].rs);
	tree[n].ts = tree[n*2].ts + tree[n*2+1].ts;
	tree[n].bs = mak3(tree[n*2].bs, tree[n*2+1].bs, tree[n*2].rs+tree[n*2+1].ls);
}
 
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n, q, pos, upd;
	cin >> n >> q;
	for(ll i=0;i<n;i++) cin >> arr[i];
	build(1,0,n-1);
	while(q--) {
		cin >> pos >> upd;
		update(1, 0, n-1, pos-1, upd);
		cout << tree[1].bs << "\n";
	}
	return 0;
}

