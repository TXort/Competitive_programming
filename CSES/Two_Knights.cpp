#include<iostream>
 
using namespace std;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	long long int i;
	for(i=1;i<=n;i++) cout <<  (i*i*(i*i-1)/2)-(2*(i-2)*(2*(i-4)+6)) << "\n";
	return 0;
}
