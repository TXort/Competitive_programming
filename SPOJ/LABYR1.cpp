#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

char lab[1002][1002];
bool vis[1002][1002];

int max1, max2, secx, secy, a, b;

void fastscan(int &x) {
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

void dfs1(int p,int x,int y) {
	if(vis[x][y] || x<0 || y<0 || x>=a || y>=b) return;
	vis[x][y] = 1;
	if(p>=max1) {
		max1 = p; secx = x; secy = y;
	}
	if(lab[x+1][y]=='.') dfs1(p+1,x+1,y);
	if(lab[x-1][y]=='.') dfs1(p+1,x-1,y);
	if(lab[x][y+1]=='.') dfs1(p+1,x,y+1);
	if(lab[x][y-1]=='.') dfs1(p+1,x,y-1);
}

int main() {
	int t; fastscan(t);
	while(t--) {
		scanf("%d %d", &b, &a);
		for(int i=0;i<a;i++)
			scanf(" %s", &lab[i]);
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				if(lab[i][j]=='.' && vis[i][j]==0) {
					dfs1(0,i,j);
				}
		max2 = max1;
		memset(vis, 0, sizeof(vis));
		dfs1(0,secx,secy);
		printf("Maximum rope length is %d.\n", max(max1,max2));
		memset(lab, 0, sizeof(lab)); memset(vis, 0, sizeof(vis)); max1 = 0; max2 = 0; secx = 0, secy = 0;
	}
	return 0;
}
