#include<iostream>
#include<tuple>
#include<queue>
#include<set>

using namespace std;

int target, a, b, c, d, ca, cb, cc, cua, cub, cuc;
set<tuple<int,int,int> > mem;
queue<tuple<int,int,int,int> > q;
pair<int,int> p;

pair<int,int> pour_to(int to, int from, int to_cap) {
	int left = from - to_cap + to;
 	if(left<0) left = 0;
	int new_to = from - left + to;
	return make_pair(new_to, left);
}

void next(int x, int y, int z, int dist) {
	tuple<int,int,int> t = make_tuple(x,y,z);
	if(mem.find(t)==mem.end()) {
		mem.insert(t);
		q.emplace(x,y,z,dist+1);
	}
}

bool check(int x, int y, int z) {
	if(x==target || y==target || z==target) return 1;
	return 0;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> target >> ca >> cb >> cc >> a >> b >> c;
	q.emplace(a,b,c,0); mem.emplace(a,b,c);
	while(!q.empty()) {
		tie(cua, cub, cuc, d) = q.front(); q.pop();
		if(check(cua,cub,cuc)) {cout << d; return 0;}
		a = cua; b = cub; c = cuc; p = pour_to(a, c, ca); a = p.first; c = p.second; next(a, b, c, d);
		a = cua; b = cub; c = cuc; p = pour_to(b, c, cb); b = p.first; c = p.second; next(a, b, c, d);
		a = cua; b = cub; c = cuc; p = pour_to(a, b, ca); a = p.first; b = p.second; next(a, b, c, d);
		a = cua; b = cub; c = cuc; p = pour_to(c, b, cc); c = p.first; b = p.second; next(a, b, c, d);
		a = cua; b = cub; c = cuc; p = pour_to(b, a, cb); b = p.first; a = p.second; next(a, b, c, d);
		a = cua; b = cub; c = cuc; p = pour_to(c, a, cc); c = p.first; a = p.second; next(a, b, c, d);
		a = cua; b = cub; c = cuc; next(0, b, c, d); next(a, 0, c, d); next(a, b, 0, d);
	}
    return 0;
}
