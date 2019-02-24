#include<iostream>
#include<vector>
#include<string>

using namespace std;

string s;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	vector<string> words(n);
	vector<char> optimal;
	vector<bool> used(255);
	for(int i=0;i<n;i++) cin >> words[i];
	int k, priority; char best;
	for(int i=0;i<n;i++) {
		k = 0; priority = 1000; best = '$';
		for(int j=0;j<words[i].size();j++) {
			if(words[i][j]=='.') {
				k = 0; continue;
			}
			if(priority>k && !used[int(words[i][j])]) {
				best = words[i][j];
				priority = k;
			}
			k++;
		}
		if(best!='$') {
			optimal.push_back(best);
			best = tolower(best); used[int(best)] = 1;
			best = toupper(best); used[int(best)] = 1;
		}
	}
	for(int i=0;i<n;i++) {
		int it = 0; bool ok = 1;
		while(it<words[i].size()) {
			if(words[i][it]==optimal[i] && ok) {
				cout << "["; cout << words[i][it] << "]"; it++; ok = 0;
			}
			cout << words[i][it];
			it++;
		}
		cout << "\n";
	}
	return 0;
}
