#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for(int i=0;i<n;i++) cin >> a[i];
		int it1 = 0, it2 = 0, z = 0;
		int temp = k; int sol = 0;
		while(it1<n) {
			if(a[it1]==0) {
				z++;
			}
			if(z<=k) {
				sol  = max(it1-it2+1, sol);
			}
			else {
				while(z>k && it2<it1) {
					if(a[it2]==0) z--;
					it2++;
				}
			}
			it1++;
		}
		cout << sol << "\n";
	}
	return 0;
}

