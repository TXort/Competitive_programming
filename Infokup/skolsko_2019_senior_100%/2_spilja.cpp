#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int n, m;

string mat[15];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> mat[i];
	int min_moves = 1000;
	for(int i=0;i<m;i++) {
		int c = 0;
		int max_gap = 0;
		for(int j=0;j<n;j++) {
			if(mat[j][i]=='.') c++;
			if(mat[j][i]=='#') c = 0;
			max_gap = max(max_gap, c);
		}
		min_moves = min(min_moves,max_gap);
	}
	for(int i=0;i<m;i++) {
		int moves = 0;
		for(int j=0;j<n;j++) {
			if(mat[j][i]=='.') {
				mat[j][i] = '#';
				moves++;
			}
			if(moves==min_moves) break;
		}
	}
	for(int i=0;i<min_moves;i++)
		for(int j=0;j<m;j++)
			mat[i][j] = '.';
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) cout << mat[i][j];
		cout << "\n";
	} 
    return 0;
}
