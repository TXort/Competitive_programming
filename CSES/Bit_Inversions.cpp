#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#define ll long long
#define MAX 200005
 
using namespace std;
 
struct node{
	ll ls1;
	ll rs1;
	ll ts1;
	ll bs1;
	ll ls2;
	ll rs2;
	ll ts2;
	ll bs2;
}tree[MAX*4];
 
ll arr1[MAX];
ll arr2[MAX];
 
ll mak3(ll a, ll b, ll c) {return max(a, max(b, c));}
 
void build(ll n, ll b, ll e)
{
 	if (b>e) return;
 	else if (b==e) {
  		tree[n].ls1 = arr1[b];
  		tree[n].rs1 = arr1[b];
  		tree[n].ts1 = arr1[b];
		tree[n].bs1 = arr1[b];
		tree[n].ls2 = arr2[b];
  		tree[n].rs2 = arr2[b];
  		tree[n].ts2 = arr2[b];
		tree[n].bs2 = arr2[b];
  		return;
 	}
 	build(n*2,b,(b+e)/2); 
	build(n*2+1,(b+e)/2+1,e);
	tree[n].ls1 = mak3(tree[n*2].ls1, tree[n*2].ts1, tree[n*2].ts1+tree[n*2+1].ls1);
	tree[n].rs1 = mak3(tree[n*2+1].rs1, tree[n*2+1].ts1, tree[n*2+1].ts1+tree[n*2].rs1);
	tree[n].ts1 = tree[n*2].ts1 + tree[n*2+1].ts1;
	tree[n].bs1 = mak3(tree[n*2].bs1, tree[n*2+1].bs1, tree[n*2].rs1+tree[n*2+1].ls1);
	tree[n].ls2 = mak3(tree[n*2].ls2, tree[n*2].ts2, tree[n*2].ts2+tree[n*2+1].ls2);
	tree[n].rs2 = mak3(tree[n*2+1].rs2, tree[n*2+1].ts2, tree[n*2+1].ts2+tree[n*2].rs2);
	tree[n].ts2 = tree[n*2].ts2 + tree[n*2+1].ts2;
	tree[n].bs2 = mak3(tree[n*2].bs2, tree[n*2+1].bs2, tree[n*2].rs2+tree[n*2+1].ls2);
}
 
void update1(ll n, ll b, ll e, ll idx, ll val) {
 	if (b>e || b>idx || e<idx) return;
 	if (b==e) {
  		tree[n].ls1 = val;
  		tree[n].rs1 = val;
  		tree[n].ts1 = val;
  		tree[n].bs1 = val;
  		return;
 	}
 	update1(n*2,b,(b+e)/2,idx,val);
 	update1(n*2+1,(b+e)/2+1,e,idx,val);
	tree[n].ls1 = mak3(tree[n*2].ls1, tree[n*2].ts1, tree[n*2].ts1+tree[n*2+1].ls1);
	tree[n].rs1 = mak3(tree[n*2+1].rs1, tree[n*2+1].ts1, tree[n*2+1].ts1+tree[n*2].rs1);
	tree[n].ts1 = tree[n*2].ts1 + tree[n*2+1].ts1;
	tree[n].bs1 = mak3(tree[n*2].bs1, tree[n*2+1].bs1, tree[n*2].rs1+tree[n*2+1].ls1);
}
 
void update2(ll n, ll b, ll e, ll idx, ll val) {
 	if (b>e || b>idx || e<idx) return;
 	if (b==e) {
  		tree[n].ls2 = val;
  		tree[n].rs2 = val;
  		tree[n].ts2 = val;
  		tree[n].bs2 = val;
  		return;
 	}
 	update2(n*2,b,(b+e)/2,idx,val);
 	update2(n*2+1,(b+e)/2+1,e,idx,val);
	tree[n].ls2 = mak3(tree[n*2].ls2, tree[n*2].ts2, tree[n*2].ts2+tree[n*2+1].ls2);
	tree[n].rs2 = mak3(tree[n*2+1].rs2, tree[n*2+1].ts2, tree[n*2+1].ts2+tree[n*2].rs2);
	tree[n].ts2 = tree[n*2].ts2 + tree[n*2+1].ts2;
	tree[n].bs2 = mak3(tree[n*2].bs2, tree[n*2+1].bs2, tree[n*2].rs2+tree[n*2+1].ls2);
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n, q, pos, upd1, upd2;
	bool x;
	string s; cin >> s;
	for(int i=0;i<s.size();i++) {
		if(s[i]-'0'==0) {
			arr1[i] = -100000000;
			arr2[i] = 1;
		}
		else if(s[i]-'0'==1) {
			arr1[i] = 1;
			arr2[i] = -100000000;
		}
	}
	n = s.size();
	build(1,0,n-1);
	cin >> q;
	while(q--) {
		cin >> pos;
		upd1 = arr1[pos-1];
		upd2 = arr2[pos-1];
		if(upd1<-1) {
			arr1[pos-1] = 1;
			update1(1, 0, n-1, pos-1, 1);
		}
		else {
			arr1[pos-1] = -100000000;
			update1(1, 0, n-1, pos-1, -100000000);
		}
		if(upd2<-1) {
			arr2[pos-1] = 1;
			update2(1, 0, n-1, pos-1, 1);			
		}
		else {
			arr2[pos-1] = -100000000;
			update2(1, 0, n-1, pos-1, -100000000);			
		}
		cout << max(tree[1].bs1,tree[1].bs2) << " ";
	}
	return 0;
}
