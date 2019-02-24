#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
#include<string>
 
using namespace std;
 
char lab[2500][2500];
int path[2500][2500];
 
queue<tuple<int,int,int> > pla;
queue<pair<int,int> > mon;
 
int n,m,x,y,d;
 
void monsters() {
	int k = mon.size();
	while(k--) {
		x = mon.front().first; y = mon.front().second; mon.pop();
		lab[x][y] = 'M';
		if(x>0 && (lab[x-1][y]=='.' || lab[x-1][y]=='A')) mon.push(make_pair(x-1,y));
		if(x<n-1 && (lab[x+1][y]=='.' || lab[x+1][y]=='A')) mon.push(make_pair(x+1,y));
		if(y>0 && (lab[x][y-1]=='.' || lab[x][y-1]=='A')) mon.push(make_pair(x,y-1));
		if(y<m-1 && (lab[x][y+1]=='.' || lab[x][y+1]=='A')) mon.push(make_pair(x,y+1));
	}
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> n >> m;
	int sx,sy;
	for(int i=0;i<n;i++) 
		for(int j=0;j<m;j++) {
			cin >> lab[i][j]; path[i][j] = -1;
			if(lab[i][j]=='M') mon.push(make_pair(i,j));
			else if(lab[i][j]=='A') {
				pla.push(make_tuple(i,j,0));
				sx = i, sy = j;
			}
		}
	int destx, desty; bool yes = 0;
	while(!pla.empty()) {
		tie(x,y,d) = pla.front(); pla.pop();
		if(path[x][y] != -1 || lab[x][y]=='M') continue;
		if(x==0 || x==n-1 || y==0 || y==m-1) {
			destx = x, desty = y, path[x][y] = d, yes = 1; break;
		}
		path[x][y] = d;
		if(x>0 && lab[x-1][y]=='.') pla.push(make_tuple(x-1,y,d+1));
		if(x<n-1 && lab[x+1][y]=='.') pla.push(make_tuple(x+1,y,d+1));
		if(y>0 && lab[x][y-1]=='.') pla.push(make_tuple(x,y-1,d+1));
		if(y<m-1 && lab[x][y+1]=='.') pla.push(make_tuple(x,y+1,d+1));
		monsters();
	}
	if(pla.empty() && !yes) {
		cout << "NO"; 
		return 0;
	}
	cout << "YES" << "\n";
	d = path[destx][desty];
	cout << d << "\n";
	string sol;
	while(sx!=destx || sy!=desty) {
		if(destx>0 && path[destx-1][desty]==d-1) {
			sol += 'D'; destx--;
		}
		else if(destx<n-1 && path[destx+1][desty]==d-1) {
			sol += 'U'; destx++;
		}
		else if(desty > 0 && path[destx][desty-1]==d-1) {
			sol += 'R'; desty--;
		}
		else {
			sol += 'L'; desty++;
		}
		d--;
	}
	reverse(sol.begin(), sol.end());
	cout << sol;
	return 0;
}
