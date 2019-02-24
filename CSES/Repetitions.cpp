#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	string s; int c = 0; int maks = 0;
	cin >> s; char h = s[0];
	for(int i=0;i<s.length();i++) {
		if(s[i]!=h) {
			h = s[i];
			c = 0;
		}
		c++;
		if(c>maks) maks = c;
	}
	cout << maks;
	return 0;
}
