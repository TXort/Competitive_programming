#include<iostream>
#include<string>
 
using namespace std;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	string s;
	cin >> s;
	int a[s.length()];
	a[0] = 0;
	int len = 0, i = 1;
	while(i<s.length()) {
		if(s[i]==s[len]) {
			len++; a[i] = len; i++;
		}
		else {
			if(len!=0) len = a[len-1];
			else {
				a[i] = 0;
				i++;
			}
		}
	}
	int sol = a[s.length()-1];
	cout << s.substr(0, sol);
	return 0;
}
