#include<iostream>
#include<string>
#include<vector>
     
using namespace std;
     
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    string s;
    cin >> s;
    vector<char> S; int sol = 0;
    for(int i=0;i<s.length();i++) {
    	if(s[i]!='H' && s[i]!='O' && s[i]!='N' && s[i]!='I') continue;
    	if(s[i]=='H' && S.empty()) S.push_back(s[i]);
    	if(s[i]=='O' && S.size()==1) S.push_back(s[i]);
    	if(s[i]=='N' && S.size()==2) S.push_back(s[i]);
    	if(s[i]=='I' && S.size()==3) S.push_back(s[i]);
    	if(S.size()==4) {
    		S.clear(); sol++;
    	}
    }
    cout << sol;
    return 0;
}
