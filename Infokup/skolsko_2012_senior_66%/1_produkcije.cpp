#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	string s; cin >> s;
	int n; cin >> n;
	vector<int> freq(255);
	vector<bool> visited(255);
	for(int i=0;i<s.size();i++) freq[int(s[i])]++;
	int sol = 0;
	char key; string ss;
	while(n--) {
		cin >> key >> ss;
		sol += (freq[int(key)]*ss.size());
		visited[int(key)] = 1;
	}
	for(int i=0;i<visited.size();i++) {
		if(!visited[i] && freq[i]) sol += freq[i];
	}
	cout << sol;
	return 0;
}
