#include<iostream> 
#include<cmath>
#include<cstring>
#define MAX 100005

using namespace std; 
int lookup[MAX][17]; 
int arr[MAX];

void fs(int &x) {
        bool neg=false;
        register int c;
        x =0;
        c=getchar();
        if(c=='-')
        {
            neg = true;
            c=getchar();
        }
        for(;(c>47 && c<58);c=getchar())
            x = (x<<1) + (x<<3) +c -48;
        if(neg)
            x *=-1;
}

void buildSparseTable(int n) { 
    for (int i=0;i<n;i++) lookup[i][0] = arr[i]; 
  
    for (int j=1;(1<<j)<=n;j++) { 
        for (int i=0;(i+(1<<j)-1)<n;i++) { 
            if (lookup[i][j-1]<lookup[i+(1<<(j-1))][j-1]) lookup[i][j] = lookup[i][j-1]; 
            else lookup[i][j] = lookup[i+(1<<(j-1))][j-1]; 
        } 
    } 
} 
  
int query(int L, int R)  { 
    int j = (int)log2(R-L+1); 
    if (lookup[L][j]<=lookup[R-(1<<j)+1][j]) return lookup[L][j]; 
    else return lookup[R-(1<<j)+1][j]; 
} 
  
int main()  { 
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t, n, q, l, r;
	fs(t);
	for(int test=1;test<=t;test++) {
		printf("Scenario #%d:\n", test);
		fs(n); fs(q);
		for(int i=0;i<n;i++) fs(arr[i]);
		buildSparseTable(n); 
		while(q--) {
			fs(l); fs(r); l--; r--;
			printf("%d\n", query(l, r));
		}
		memset(lookup, 0, sizeof(lookup));
		memset(arr, 0, sizeof(arr));
	}
    return 0; 
} 


