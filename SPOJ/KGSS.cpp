#include<iostream>
#define MAX 100000

using namespace std;

struct node{
	int ma;
	int secma;
	void merge(node left, node right) {
		ma = max(left.ma,right.ma);
		if(left.ma==ma) {
			secma = max(left.secma,right.ma);
		}
		else secma = max(left.ma,right.secma);
		
	}
} tree[MAX*4];

int arr[MAX];

void build(int n, int b, int e) {
 	if (b>e) return;
 	else if (b==e) {
  		tree[n].ma = arr[b];
  		tree[n].secma = 0;
  		return;
 	}
 	int mid = (b+e)/2;
 	build(n*2,b,mid); 
	build(n*2+1,mid+1,e);
 	tree[n].merge(tree[n*2],tree[n*2+1]);
}

void update(int n, int b, int e, int idx, int val) {
	if (b>e || b>idx || e<idx ) return;
 	if (b==e) {
 	 tree[n].ma = val;
  tree[n].secma = 0;
  return;
 }
 int mid = (b+e)/2;
 update(n*2,b,mid,idx,val);
 update(n*2+1,mid+1,e,idx,val);
 tree[n].merge(tree[n*2],tree[n*2+1]);
}

node query(int n, int b, int e, int i, int j) {
	node sol;
	sol.ma = 0;
	sol.secma = 0;
 	if (i>e || b>j) return node{0,0};
 	if (b>=i && e<=j) {
 	return tree[n];
 	}
 	int mid = (b+e)/2;
 	sol.merge(query(n*2,b,mid,i,j),query(n*2+1,mid+1,e,i,j));
 	return sol;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,q,a,b,s,s1; char c;
	cin >> n;

	for(int i=0;i<n;i++) cin >> arr[i];
	build(1, 0, n-1);

	cin >> q;
	while(q--) {
		cin >> c >> a >> b;
		if(c=='Q') {
			node s = query(1, 0, n-1, a-1, b-1);
			cout << s.ma + s.secma << "\n";
		}
		else update(1,0,n-1,a-1,b);
	}
	
	return 0;
}

