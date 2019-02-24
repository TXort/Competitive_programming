#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	string s;
	cin >> s;
	string d = s + s;
	int k = 0;
	vector<int> f(d.size(),-1);
	for(int j=1;j<d.size();j++) {
		char sj = d[j];
		int i = f[j-k-1];
		while(i!=-1 and sj!=d[k+i+1]) {
			if(sj<d[k+i+1]) k = j-i-1;
			i = f[i];
		}
		if(sj!=d[k+i+1]) {
			if(sj<d[k]) k = j;
			f[j-k] = -1;
		}
		else f[j-k] = i + 1;
	}
	cout << k;
	return 0;
}
