#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int graf[5001][3];
 
const long long int INF = 100000000000000000LL;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,m,a,b,c,x;
	cin >> n >> m;
	vector<long long int> dist(n,INF);
	bool yes = 0;
	for(int i=0;i<m;i++) {
		cin >> a >> b >> c; a--;b--;
		graf[i][0] = a; graf[i][1] = b; graf[i][2] = c;
	}
	vector<int> p(n);
	dist[0] = 0;
	for(int i=0;i<n-1;i++)
		for(int j=0;j<m;j++)
			if(dist[graf[j][1]]>dist[graf[j][0]] + graf[j][2]) {
				dist[graf[j][1]] = dist[graf[j][0]] + graf[j][2];
				p[graf[j][1]] = graf[j][0]; x = graf[j][1]; }
	for(int j=0;j<m;j++) {
		if(dist[graf[j][1]]>dist[graf[j][0]] + graf[j][2]) {
			dist[graf[j][1]] = dist[graf[j][0]] + graf[j][2];
			p[graf[j][1]] = graf[j][0]; x = graf[j][1];
			yes = 1;
		}
	}
	if(!yes) {
		cout << "NO"; 
		return 0;
	}
	cout << "YES" << "\n";
	for (int i = 0; i < n; i++) x = p[x];
	int o = x;
    vector<int> g(1, o);
    do {
      	x = p[x];
      	g.push_back(x);
	} while (x != o);
	reverse(g.begin(),g.end());
	for (int i = 0; i < g.size(); i++) {
     	 cout << g[i] + 1;
     	 if (i < g.size() - 1) cout << " ";
	}
	return 0;
}
