#include<iostream>

using namespace std;

int main(){
	int n , k; cin >> n >> k;
	int m; cin >> m;
	n-=n%k;
	while(m--) {
		int a,b; cin >> a >> b;a--; b--;
		if(a/k == b/k && a < n && b < n) cout << "DA" << endl;
		else cout << "NE" << endl;
	}
	return 0;
}

