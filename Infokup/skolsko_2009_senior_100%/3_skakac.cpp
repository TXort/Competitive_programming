#include<iostream>
#include<cstring>

using namespace std;

int n,m,stx,sty,steps;
int mat[11][11];
int mem[11][11][11][11][101];
const int move_row[8] = {1,2,2,1,-1,-2,-2,-1};
const int move_column[8] = {-2,-1,1,2,2,1,-1,-2};

int recursion(int x,int y,int px,int py,int k) {
	if(k<0) return 0;
	if(mem[x][y][px][py][k] >= 0) return mem[x][y][px][py][k];
	mem[x][y][px][py][k] = 0;
	for(int i=0;i<8;i++) {
		int row = x + move_row[i];
		int column = y + move_column[i];
		if(row==px && column==py) continue;
		if(row<0 || row>=n) continue;
		if(column<0 || column>=m) continue;
		mem[x][y][px][py][k] = max(mem[x][y][px][py][k],mat[x][y] + recursion(row,column,x,y,k-1));
	}
	return mem[x][y][px][py][k];
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> mat[i][j];
	memset(mem, -1, sizeof(mem));
	cin >> stx >> sty >> steps;
	cout << recursion(stx-1,sty-1,stx-1,sty-1,steps);
	return 0;
}
