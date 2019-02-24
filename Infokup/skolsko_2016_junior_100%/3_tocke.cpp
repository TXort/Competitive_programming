#include<iostream>
#include<vector>

using namespace std;

string lit[101];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n; cin >> n;
	vector<pair<int,int> > vpii(n);
	vector<vector<pair<int,int> > > mat;
	mat.insert(mat.begin(),n,vpii);
	int sol = 0;
	for(int i=0;i<n;i++) cin >> lit[i];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) mat[i][j].first = mat[i][j].second = 1;
	for(int i=0;i<n;i++) {
		if(i>0 && lit[0][i]==lit[0][i-1]) mat[0][i].first = mat[0][i-1].first + 1;
		if(i>0 && lit[0][n-i]==lit[0][n-i-1]) mat[0][n-i-1].second = mat[0][n-i].second + 1;
		sol = max(sol,max(mat[0][i].first,mat[0][i].second));
	}
	for(int i=1;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(lit[i][j]==lit[i-1][j]) mat[i][j].first = max(mat[i-1][j].first + 1,mat[i-1][j].second + 1);
			if(j>0 && lit[i][j]==lit[i][j-1]) mat[i][j].first = max(mat[i][j].first, mat[i][j-1].first + 1);
			if(lit[i][n-j-1]==lit[i-1][n-j-1]) mat[i][n-j-1].second = max(mat[i-1][n-j-1].second + 1, mat[i-1][n-j-1].first + 1);
			if(j>0 && lit[i][n-j]==lit[i][n-j-1]) mat[i][n-j-1].second = max(mat[i][n-j-1].second, mat[i][n-j].second + 1); 
			sol = max(sol,max(mat[i][j].first,mat[i][j].second));
		}
	}
	cout << sol;
	return 0;
}
