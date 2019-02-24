#include<iostream>
#include<vector>
#include<set>
#include<cmath>
#include<tuple>
#define ll long long
 
using namespace std;
 
	const ll inf = 100000000000000;
	vector <vector<pair<ll,ll> > > graf;
	
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,m,x=0;
	cin >> n >> m;
	vector<ll> bio(n,0);
	vector<ll> dist(n,inf);
	vector<ll> roditelj(n,-1);
	vector<pair<ll,ll> > vpii;
	graf.insert(graf.begin(),n,vpii);
	set<tuple<ll,ll,ll> > najblizi;
	for(int i=0;i<n;i++) najblizi.insert(make_tuple(inf,i,0));
	ll a,b,c;
	for(int i=0;i<m;i++) {
		cin >> a >> b >> c; a--; b--;
		graf[a].push_back(make_pair(b,c));
	}
	dist[x] = 0;
	najblizi.erase(make_tuple(inf,x,0));
	najblizi.insert(make_tuple(0,x,0));
	ll udaljenost, cvor, u = 0;
	pair<ll,ll> pii; ll mak = 0;
	while(404) {
		tie(udaljenost,cvor,u) = *(najblizi.begin());
		najblizi.erase(najblizi.begin());
		if (cvor == n - 1) {
      		cout << udaljenost-(u-u/2) << endl;
			break;
		}
		bio[cvor]=1;
		for(int j=0;j<graf[cvor].size();j++)
			if(!bio[graf[cvor][j].first])
				if(dist[graf[cvor][j].first] > udaljenost + graf[cvor][j].second) {
					pii=graf[cvor][j];
					roditelj[pii.first]=cvor;
					najblizi.erase(make_tuple(dist[pii.first],pii.first,max(u,pii.second)));
					dist[pii.first]=udaljenost+pii.second;
					najblizi.insert(make_tuple(udaljenost+pii.second,pii.first,max(u,pii.second)));
				}	 	
	}
	return 0;
}
