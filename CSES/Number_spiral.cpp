#include<iostream>
#include<cmath>
using namespace std;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while(t--) {
		int x,y;
		cin >> y >> x;
		long long int veci = max(x,y);
		long long int manji= min(x,y);
		long long int sol = (veci-1)*(veci-1);;
		if(veci==manji) sol += x;
		else if(veci%2) {
			if(x==veci) sol+= veci * 2 - y;
			else sol+= x;
		}
		else
			if(y==veci) sol+= veci * 2 - x;
			else sol+= y;			
		cout << sol;
	}
	return 0;
}
