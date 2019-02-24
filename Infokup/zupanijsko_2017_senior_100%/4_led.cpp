#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#define inf 100000000
#define MAX 2008

using namespace std;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

int n, x, y, nx, ny, dist, scenario, bombrange, sol;

bool visited[MAX][MAX];
char mat[MAX][MAX];
int trace_0[MAX][MAX];
int trace_1[MAX][MAX];
int help0[MAX][MAX];
int help1[MAX][MAX];

struct MinQ {
	queue<int> q;
	deque<int> m;
	int min() {return m.front();}
	void push(int x) {
		q.push(x);
		while(!m.empty() && m.back()>x) m.pop_back();
		m.push_back(x);
	}
	void pop() {
		if(m.front()==q.front()) m.pop_front();
		q.pop();
	}
};

void preprocess0(int window, int (&a)[MAX][MAX]) {
	for(int i=0;i<n;i++) {
		MinQ sliding_min;
		for(int j=0;j<window;j++) sliding_min.push(a[i][j]);
		for(int j=0;j<n;j++) {
			a[i][j] = sliding_min.min();
			if(j+window<n) sliding_min.push(a[i][j+window]);
			sliding_min.pop();
		}
	}
	return;
}

void preprocess1(int window, int (&a)[MAX][MAX]) {
	for(int i=0;i<n;i++) {
		MinQ sliding_min;
		for(int j=0;j<window;j++) sliding_min.push(a[j][i]);
		for(int j=0;j<n;j++) {
			a[j][i] = sliding_min.min();
			if(j+window<n) sliding_min.push(a[j+window][i]);
			sliding_min.pop();
		}
	}
	return;
}

void bfs01(int startx, int starty, int endx, int endy, int type) {
	memset(visited,0,sizeof(visited));
	deque<pair<int,pair<int,int > > > q;
	q.push_back(make_pair(0,make_pair(startx,starty)));
	while(!q.empty()) {
		dist = q.back().first;
		x = q.back().second.first;
		y = q.back().second.second;
		q.pop_back();
		if(visited[x][y]) continue;
		if(type==0) trace_0[x][y] = dist;
		else if(type==1) trace_1[x][y] = dist;
		visited[x][y] = 1;
		for(int i=0;i<4;i++) {
			nx = x + dx[i]; ny = y + dy[i];
			if(nx<0 || nx>=n || ny<0 || ny>=n || visited[nx][ny]) continue;
			if(mat[nx][ny]=='1') q.push_front(make_pair(dist+1,make_pair(nx,ny)));
			else if(mat[nx][ny]=='0') q.push_back(make_pair(dist,make_pair(nx,ny)));
		}
	}
	return;
}

int solve(int sol) {
	preprocess0(bombrange,trace_0);
	preprocess1(bombrange,trace_0);
	preprocess0(bombrange,trace_1);
	preprocess1(bombrange,trace_1);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) help0[i][j] = trace_0[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) {
			help0[i][j] = trace_0[i][j];
			if(i+1<n) help0[i][j] = min(help0[i][j], trace_0[i+1][j]);
			if(i-1>=0) help0[i][j] = min(help0[i][j], trace_0[i-1][j]);
			if(j+1<n) help0[i][j] = min(help0[i][j], trace_0[i][j+1]);
			if(j-1>=0) help0[i][j] = min(help0[i][j], trace_0[i][j-1]);
		}
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) trace_0[i][j] = help0[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) {
			help1[i][j] = trace_1[i][j];
			if(i+1<n) help1[i][j] = min(help1[i][j], trace_1[i+1][j]);
			if(i-1>=0) help1[i][j] = min(help1[i][j], trace_1[i-1][j]);
			if(j+1<n) help1[i][j] = min(help1[i][j], trace_1[i][j+1]);
			if(j-1>=0) help1[i][j] = min(help1[i][j], trace_1[i][j-1]);
		}
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) trace_1[i][j] = help1[i][j];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) sol = min(sol, trace_0[i][j]+trace_1[i][j]);
	return sol;
}

int main() {
	scanf("%d", &n);
	for(int i=0;i<n;i++) {scanf("%s", mat[i]);}
	scanf("%d", &scenario);
	int sx,sy,ex,ey;
	while(scenario--) {
		sol = inf;
		scanf("%d %d %d %d %d", &bombrange, &sx, &sy, &ex, &ey);
		bfs01(sx-1,sy-1,ex-1,ey-1,0); bfs01(ex-1,ey-1,sx-1,sy-1,1);
		printf("%d\n", solve(sol));
	}
	return 0;
}
