#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int k,n,x;
	cin >> k >> n >> x;
	cout << x-k << endl;
	cout << k+n-x << endl;
	if(x-k<=k+n-x) cout << x-k;
	else cout << k+n-x;
	return 0;
}
