#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

	const int inf = 1000000;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin >> t;
	while(t--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		vector <vector<pair<int,int> > > graf;
		vector <int> bio(n,0);
		vector <int> dist(n,inf);
		vector <pair<int,int> > vpii;
		graf.insert(graf.begin(),n,vpii);
		priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;
		for (int i = 0; i < m; i++) {
    		int a, b, c;
    		cin >> a >> b >> c; a--; b--;
			graf[a].push_back(make_pair(b,c));
			graf[b].push_back(make_pair(a,c));
		}
		x--; y--;
		pq.push(make_pair(0,x));
		dist[x] = 0;
		int d, c; int v, w;
		while(!pq.empty()) {
			tie(d, c) = pq.top(); pq.pop();
			bio[c] = 1;
			for(auto i:graf[c]) {
				tie(v, w) = i;
				if(bio[v]) continue;
				if(d+w < dist[v]) {
					dist[v] = d+w;
					pq.push(make_pair(d+w,v));
				}
			}
		}
		dist[y] < inf ? cout << dist[y] << "\n" : cout << "NONE" << "\n";
	}
	return 0;
}

