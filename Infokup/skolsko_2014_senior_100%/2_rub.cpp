#include<iostream>
#include<vector>
#include<string>

using namespace std;

int r, s;
int max_area = 0;

bool check(const vector<string> &m, int sx, int sy, int ex, int ey, char c) { 
	  bool valid = 1;
	  int csx = sx, csy = sy, cex = ex, cey = ey;
	  int a, b = 0;
	  for(int i=sx;i<=ex;i++) {
			if(m[i][sy]!=m[i][ey]) valid = 0;
			a++;
	  }
	  for(int i=sy;i<=ey;i++) {
	  		if(m[sx][i]!=m[ex][i]) valid = 0;
	  		b++;
	  }
	  if(valid) {
	  		max_area = max(max_area, a*b);
	  		return 1;
	  }
	  else return 0;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> r >> s;
	vector<string> mat(r);
	int sol = 0;
	for(int i=0;i<r;i++) cin >> mat[i];
	for(int i=0;i<r;i++)
		for(int j=0;j<s;j++)
			for(int k=i+1;k<r;k++)
				for(int l=j+1;l<s;l++)
					if(mat[i][j]==mat[k][l] && check(mat,i,j,k,l,mat[i][j])) sol++;
	cout << sol << " " << max_area;
	return 0;
}
