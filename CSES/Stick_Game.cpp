#include<iostream>
 
using namespace std;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
  	int t, x, n, k;
  	cin >> t;
  	while(t--) {
  		cin >> n; k = 0;
  		for(int i=0;i<n;i++) {
  			cin >> x; k ^= x%4;
	  	}
		cout << (k ? "first\n" : "second\n");
  	}
  	return 0;
 }
