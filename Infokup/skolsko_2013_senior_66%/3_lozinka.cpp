#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

set<string> s;
vector<pair<int,int> > pos;

void recursion(string s, int target) {
	int x = pos[target].first;
	
	
	
	
}




int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	string s; cin >> s;
	int level = 0;
	for(int i=0;i<s.length();i++) {
		if(s[i]=='(') {
			pos.push_back(make_pair(i,level));
			level++;
		}
		if(s[i]==')') {
			level--;
			pos.push_back(make_pair(i,level));
		}		
	}
	
	
	return 0;
}
