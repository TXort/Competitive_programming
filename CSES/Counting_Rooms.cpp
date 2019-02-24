#include<iostream>
 
using namespace std;
 
int n, m, sol;
char a[2501][2501];
bool v[2501][2501];
 
void ff(int x, int y) {
	if(v[x][y] || a[x][y]=='#' || x>=n || y>=m || x<0 || y<0) return;
	v[x][y] = 1;
	ff(x+1,y); ff(x,y+1); ff(x-1,y); ff(x,y-1);
}
 
int main() {
	scanf("%d %d", &n,&m);
	for(int i=0;i<n;i++) scanf("%s", a[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!v[i][j] && a[i][j]=='.') {
				sol++;
				ff(i, j);
			}
	printf("%d", sol);
	return 0;
}
