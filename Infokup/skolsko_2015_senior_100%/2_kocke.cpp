#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n; cin >> n;
	vector<int> p1, p2;
	short curr1 = 1; char c;
	for(int i=0;i<n;i++) {
		cin >> c;
		if(c=='P') {
			p1.push_back(curr1);
			continue;
		}
		if(curr1 == 1) {
			if(c=='R') curr1 = 2;
			else if(c=='L') curr1 = 5;
			else if(c=='U') curr1 = 3;
			else if(c=='D') curr1 = 4;
		}
		else if(curr1 == 2) {
			if(c=='R') curr1 = 5;
			else if(c=='L') curr1 = 1;
			else if(c=='U') curr1 = 3;
			else if(c=='D') curr1 = 4;			
		}
		else if(curr1 == 3) {
			if(c=='R') curr1 = 2;
			else if(c=='L') curr1 = 5;
			else if(c=='U') curr1 = 4;
			else if(c=='D') curr1 = 1;				
		}
		else if(curr1 == 4) {
			if(c=='R') curr1 = 2;
			else if(c=='L') curr1 = 5;
			else if(c=='U') curr1 = 1;
			else if(c=='D') curr1 = 3;				
		}
		else if(curr1 == 5) {
			if(c=='R') curr1 = 1;
			else if(c=='L') curr1 = 6;
			else if(c=='U') curr1 = 3;
			else if(c=='D') curr1 = 4;				
		}
		else if(curr1 == 6) {
			if(c=='R') curr1 = 5;
			else if(c=='L') curr1 = 2;
			else if(c=='U') curr1 = 3;
			else if(c=='D') curr1 = 4;				
		}
		p1.push_back(curr1);			
	}
	short curr2 = 1;
	for(int i=0;i<n;i++) {
		cin >> c;
		if(c=='P') {
			p2.push_back(curr2);
			continue;
		}
		if(curr2 == 1) {
			if(c=='R') curr2 = 2;
			else if(c=='L') curr2 = 5;
			else if(c=='U') curr2 = 3;
			else if(c=='D') curr2 = 4;
		}
		else if(curr2 == 2) {
			if(c=='R') curr2 = 5;
			else if(c=='L') curr2 = 1;
			else if(c=='U') curr2 = 3;
			else if(c=='D') curr2 = 4;			
		}
		else if(curr2 == 3) {
			if(c=='R') curr2 = 2;
			else if(c=='L') curr2 = 5;
			else if(c=='U') curr2 = 4;
			else if(c=='D') curr2 = 1;				
		}
		else if(curr2 == 4) {
			if(c=='R') curr2 = 2;
			else if(c=='L') curr2 = 5;
			else if(c=='U') curr2 = 1;
			else if(c=='D') curr2 = 3;				
		}
		else if(curr2 == 5) {
			if(c=='R') curr2 = 1;
			else if(c=='L') curr2 = 6;
			else if(c=='U') curr2 = 3;
			else if(c=='D') curr2 = 4;				
		}
		else if(curr2 == 6) {
			if(c=='R') curr2 = 5;
			else if(c=='L') curr2 = 2;
			else if(c=='U') curr2 = 3;
			else if(c=='D') curr2 = 4;				
		}
		p2.push_back(curr2);			
	}
	short sol = 0;
	for(int i=0;i<n;i++)
		if(p1[i]==p2[i]) sol++;
	cout << sol+1;
	return 0;
}
