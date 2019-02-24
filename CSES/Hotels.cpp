#include<iostream>
#define MAX 200000
 
using namespace std;
 
struct node{
	int ma;
	int indx;
} tree[MAX*4];
 
int arr[MAX];
 
void build(int n, int b, int e)
{
 	if (b>e) return;
 	else if (b==e) {
  		tree[n].ma = arr[b];
  		tree[n].indx = b + 1;
  		return;
 	}
 	build(n*2,b,(b+e)/2); 
	build(n*2+1,(b+e)/2+1,e);
 	tree[n].ma = max(tree[n*2].ma,tree[n*2+1].ma);
}
 
void update(int a, int b) {
	tree[a].ma=b;
	for(a/=2;a;a/=2) tree[a].ma = max(tree[a*2].ma, tree[a*2+1].ma);
}
 
int lo(int n, int x) {
	while(tree[n].indx==0) {
		if(x<=tree[2*n].ma) n=n*2;
		else n=n*2+1;
	}
	return n;
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n, m, q, loc;
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> arr[i];
	build(1, 0, n-1);
 
	while(m--) {
		cin >> q;
		loc = lo(1, q);
		if(tree[loc].ma<q) {
			cout << 0 << " ";
			continue;
		} 
		cout << tree[loc].indx  << " ";
		if(tree[loc].ma>=q) update(loc, tree[loc].ma-q);
	}
	
	return 0;
}
