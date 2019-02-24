#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n, m; cin >> n;
	vector<string> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	cin >> m;
	string q,s1,s2;
	int cord1,cord2,dist,size;
	for(int i=0;i<m;i++) {
		cin >> q;
		if(q.size()==5) {
			cin >> s1 >> s2;
			for(int j=0;j<a.size();j++) {
				if(a[j]==s1) cord1 = j;
				if(a[j]==s2) cord2 = j;
			}
			size = a.size();
			dist = min(abs(cord1-cord2),size-abs(cord1-cord2));
			cout << dist << "\n";
		}
		else if(q.size()==6) {
			cin >> s1;
			for(int j=0;j<a.size();j++)	if(a[j]==s1) a.erase(a.begin()+j);
		}
	}
	return 0;
}
