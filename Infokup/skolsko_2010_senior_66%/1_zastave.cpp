#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

string mat[6];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	for(int i=0;i<6;i++) cin >> mat[i];
	vector<int> a(255, 0);
	int sol1 = 0, sol2 = 0;
	int best = 0;
	for(int i=0;i<2;i++)
		for(int j=0;j<9;j++) {
			a[int(mat[i][j])]++;
			best = max(best,a[int(mat[i][j])]);			
		}
	sol1 += 18-best;
	fill(a.begin(), a.end(), 0); best = 0;
	for(int i=2;i<4;i++)
		for(int j=0;j<9;j++) {
			a[int(mat[i][j])]++;
			best = max(best,a[int(mat[i][j])]);			
		}
	sol1 += 18-best;
	fill(a.begin(), a.end(), 0); best = 0;
	for(int i=4;i<6;i++)
		for(int j=0;j<9;j++) {
			a[int(mat[i][j])]++;
			best = max(best,a[int(mat[i][j])]);			
		}
	sol1 += 18-best;
	fill(a.begin(), a.end(), 0); best = 0;
	for(int i=0;i<6;i++)
		for(int j=0;j<3;j++) {
			a[int(mat[i][j])]++;
			best = max(best,a[int(mat[i][j])]);			
		}
	sol2 += 18-best;
	fill(a.begin(), a.end(), 0); best = 0;
	for(int i=0;i<6;i++)
		for(int j=3;j<6;j++) {
			a[int(mat[i][j])]++;
			best = max(best,a[int(mat[i][j])]);			
		}
	sol2 += 18-best;
	fill(a.begin(), a.end(), 0); best = 0;
	for(int i=0;i<6;i++)
		for(int j=6;j<9;j++) {
			a[int(mat[i][j])]++;
			best = max(best,a[int(mat[i][j])]);			
		}
	sol2 += 18-best;	
	cout << min(sol1,sol2);
	return 0;
}
