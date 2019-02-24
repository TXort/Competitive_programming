#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int n, gap, start;
string s, test;
unordered_set<string> us;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> s >> n;
	for(int i=start;i<s.length();i++) {
		gap = 0;
		while(gap<s.length()) {
			gap++; string ss = "";
			for(int j=i;j<s.length();j+=gap) {
				if(j>s.length()) break;
				ss += s[j];
			}
			for(int j=0;j<ss.length();j++) 
				for(int k=1;k<=ss.length()-j;k++) 
					us.insert(ss.substr(j,k));
		}
	}
	while(n--) {
		cin >> test;
		if(us.find(test)!=us.end()) cout << "DA" << "\n";
		else cout << "NE" << "\n";
	}
    return 0;
}
