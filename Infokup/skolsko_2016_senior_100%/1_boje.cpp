#include<iostream>
#include<string>

using namespace std;

string mat[5];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	char c; cin >> c;
	for(int i=0;i<5;i++) 
		for(int j=0;j<5;j++) {
			cin >> mat[i][j];
			if(mat[i][j]==c) mat[i][j]='X';
		}
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			if(mat[i][j]=='X' && i!=0)
				for(int k=i;k>0;k--) {
					mat[k][j] = mat[k-1][j];
					mat[k-1][j] = 'X';
				}
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) cout << mat[i][j];
		cout << "\n";
	}
	return 0;
}
