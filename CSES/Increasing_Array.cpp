#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n; ll x; ll sol = 0; ll z;
	cin >> n;
	cin >> x; n--;
	while(n--) {
		cin >> z; ll h = 0;
		if(x>z) {
			sol += (x-z);
			x = z + (x-z);
		}
		else x = z;
	}
	cout << sol;
	return 0;
}
