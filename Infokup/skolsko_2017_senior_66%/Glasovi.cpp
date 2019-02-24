#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n, m, suma = 0;;
	cin >> n >> m;
	vector<int> kan(n);
	vector<bool> vis(n);
	vector<int> first(1000003, -1);
	for(int i=0;i<n;i++) {
		cin >> kan[i];
		suma += kan[i];
		if(first[kan[i]]==-1) first[kan[i]] = i;
	}
	double prolaz = suma * 0.1;
	for(int i=n-1;i>=0;i--) {
		if(kan[i]>=prolaz && m && !vis[i]) {
			for(int j=first[kan[i]];j<=i;j++) {
				vis[j] = 1; m--;
				if(!m) break;
			}
		}
	}
	if(m) {
		for(int i=0;i<n;i++)
			if(!vis[i] && m) {
				vis[i] = 1; m--;
			}
	}
	for(int i=0;i<n;i++) cout << vis[i];
	return 0;
}
