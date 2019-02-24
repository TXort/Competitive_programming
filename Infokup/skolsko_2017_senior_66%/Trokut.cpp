#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int adjmatrix[21][21];
int helpmatrix[21][21];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n, m;
	cin >> n >> m;
	map<string,int> M;
	int id = 0;
	for(int i=0;i<m;i++) {
		string s1, s2;
		int x, y;
		cin >> s1 >> s2;
		auto it1 = M.find(s1);
		if(it1!=M.end()) x = it1->second;
		else {
			M.insert({s1,id});
			x = id;
			id += 1;
		}
		auto it2 = M.find(s2);
		if(it2!=M.end()) y = it2->second;
		else {
			M.insert({s2,id});
			y = id;
			id += 1;			
		}
		adjmatrix[x][y] = adjmatrix[y][x] = 1;
	}
	for(auto p:M) {
		int node = p.second; int sol = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				helpmatrix[i][j] = adjmatrix[i][j];
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(i!=node && j!=node && !helpmatrix[i][j] && helpmatrix[i][node] && helpmatrix[j][node])
					helpmatrix[i][j] = helpmatrix[j][i] = 1;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				for(int k=j+1;k<n;k++)
					if(helpmatrix[i][j] && helpmatrix[j][k] && helpmatrix[i][k])
						sol++;
		cout << p.first << " " << sol << "\n";
	}
	return 0;
}
