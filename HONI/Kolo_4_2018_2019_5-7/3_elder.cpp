#include<iostream>
#include<vector>
#include<set>

using namespace std;


int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    char nosilac;
    cin >> nosilac;
    int n, cnt;
    cin >> n;
    char a, b;
    set<char> s;
    s.insert(nosilac);
    for(int i=0;i<n;i++) {
    	cin >> a >> b;
    	if(nosilac==b) {
    		nosilac = a;
			s.insert(a);	
    	}
	}
	cout << nosilac << "\n" << s.size();
    return 0;
}
