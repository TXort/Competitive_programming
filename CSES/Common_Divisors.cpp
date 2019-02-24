#include<iostream>
 
using namespace std;
 
int a[500005];
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
 	int n, var, c = 0, maks = 0;
 	cin >> n;
 	for(int i=0;i<n;i++) {
		cin >> a[i]; maks = max(maks, a[i]);
	}
	int carr[maks+1] = {0};
	for(int i=0;i<n;i++) carr[a[i]]++;
	for(int i=maks; i>=1; i--) {
		var = i; c = 0;
		while(var <= maks) {
			if(carr[var]>=2) {
				cout << var; return 0;
			}
			else if(carr[var] == 1) c++;
			var += i;
			if(c==2) {
				cout << i; return 0;
			}
		}
	}
    return 0;
}
