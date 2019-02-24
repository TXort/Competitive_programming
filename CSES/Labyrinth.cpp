#include<iostream>
#include<string>
#include<algorithm>
#include<tuple>
#include<queue>
 
char a[2501][2501];
int v[2501][2501];
 
using namespace std;
 
int n,m;
string sol;
int bi, bj, ai, aj;
int x, y, d;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			v[i][j] = -1;
			if(a[i][j]=='A') {
				ai = i; aj = j;
			}
			if(a[i][j]=='B') {
				bi = i; bj = j;
			}
		}
	queue<tuple<int,int,int> > q;
	q.push(make_tuple(ai,aj,0));
	while(!q.empty()) {
		tie(x,y,d) = q.front();
		q.pop();
		if(v[x][y] != -1 || a[x][y]=='#' || x>=n || y>=m || x<0 || y<0) continue;
		v[x][y] = d;
		if(x==bi && y==bj) break;
		if(x>0 && a[x-1][y]!='#' && v[x-1][y]==-1) q.push(make_tuple(x-1,y,d+1));
		if(x<n-1 && a[x+1][y] != '#' && v[x+1][y]==-1) q.push(make_tuple(x+1,y,d+1));
		if(y>0 && a[x][y-1] != '#' && v[x][y-1]==-1) q.push(make_tuple(x,y-1,d+1));
		if(y<m-1 && a[x][ +1] != '#' && v[x][y+1] == -1) q.push(make_tuple(x,y+1,d+1));
	}
	if(q.empty()) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << "\n";
	cout << d << "\n";
	while(ai!=bi || aj!=bj) {
		if(bi>0 && v[bi-1][bj]==d-1) {
			sol += 'D'; bi--;
		}
		else if(bi<n-1 && v[bi+1][bj]==d-1) {
			sol += 'U'; bi++;
		}
		else if(bj > 0 && v[bi][bj-1]==d-1) {
			sol += 'R'; bj--;
		}
		else {
			sol += 'L'; bj++;
		}
		d--;
	}
	reverse(sol.begin(), sol.end());
	cout << sol;
	return 0;
}
	
