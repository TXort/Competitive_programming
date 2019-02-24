#include<iostream>
#include<cmath>
#include<limits>
#define ll long long
#define imi std::numeric_limits<int>::min()
#define MAX 70005
 
using namespace std;

int mak3(int a, int b, int c) {return max(a, max(b, c));}

struct node{
	int ls;
	int rs;
	int ts;
	int bs;
}tree[MAX*4];

int arr[MAX];
 
node merge(node left, node right) {
	node sol;
	sol.bs = mak3(left.bs,right.bs,left.rs+right.ls);
	sol.ls = mak3(left.ls,left.ts,left.ts+right.ls);
	sol.rs = mak3(right.rs,right.ts,right.ts+left.rs);
	sol.ts = left.ts + right.ts;
	return sol;
}

 
void build(int n, int b, int e)
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
	tree[n] = merge(tree[n*2],tree[n*2+1]);
}

node query(int n, int b, int e, int i, int j)
{
	if (i>e || b>j) return node{imi,imi,imi,imi};
 	if (b==i && e==j) return tree[n];
 	int mid = (b+e)/2;
 	if(j<=mid) return query(n*2,b,mid,i,j);
 	if(i>mid) return query(n*2+1,mid+1,e,i,j);
 	return merge(query(n*2,b,mid,i,mid),query(n*2+1,mid+1,e,mid+1,j));
}
 
int main() {
	int n, q;
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &arr[i]);
	build(1,0,n-1);
	int a, b;
	scanf("%d", &q);
	while(q--) {
		scanf("%d %d",&a,&b);
		node no = query(1, 0, n-1, a-1, b-1);
		printf("%d\n", no.bs);
	}
	return 0;
}

