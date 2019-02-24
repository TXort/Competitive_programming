#include<iostream>
#include<queue>
#define ll long long
using namespace std;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int x, n, z;
	cin >> x >> n;
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=0;i<n;i++) {
		cin >> z;
		pq.push(z);
	}
	unsigned ll cost = 0; int prvi, drugi;
	while(pq.size()>1) {
		prvi = pq.top(); pq.pop();
		drugi = pq.top(); pq.pop();
		cost += prvi + drugi; 
		pq.push(prvi+drugi);
	}
	cout << cost;
	return 0;
}
