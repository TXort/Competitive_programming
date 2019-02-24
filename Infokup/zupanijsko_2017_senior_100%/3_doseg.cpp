#include<algorithm>
#include<iostream>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

stack<map<char,int> > program;
map<char,int> values;
string s;
int n;

int main() {
	cin >> n; n++;
	program.push(values);
	while(n--) {
		getline(cin, s);
		values = program.top();
		if(s=="begin") program.push(values);
		else if(s=="end") program.pop();
		else if(s[0]=='v') {
			char key = s[4];
			string value_string = s.substr(8, s.size()-1);
			int value = stoi(value_string);
			values[key] = value;
			program.pop();
			program.push(values);
		}
		else if(s[0]=='w') {
			char key = s[6];
			int val = values.find(key)->second;
			cout << val << "\n";
		}
	}
	return 0;
}
