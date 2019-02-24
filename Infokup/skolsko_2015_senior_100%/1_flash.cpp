#include<iostream>

using namespace std;

char a[82];
char wanted[82];
bool help[21];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int m, k; cin >> m >> k;
	for(int i=0;i<m*(k+1)-1;i++) cin >> a[i];
	for(int i=0;i<m*(k+1)-1;i++) cin >> wanted[i];
	int block = 0, sol = 0;
	for(int i=0;i<m*(k+1)-1;i++) {
		if(a[i]=='|') {
			block++; continue;
		}
		if(wanted[i]=='1' && a[i]=='0') help[block] = 1;
	}
	block = 0, sol = 0; bool flag = 1;
	for(int i=0;i<m*(k+1)-1;i++) {
		if(a[i]=='|') {
			block++; flag = 1; continue;
		}
		if(help[block] && flag) {
			flag = 0; sol += 100;
		}
		if(help[block]) {
			if(wanted[i]=='0') sol++;
		}
		else{
			if(a[i]=='1' && wanted[i]=='0') sol++;
		}
	}
	cout << sol;
	return 0;
}
