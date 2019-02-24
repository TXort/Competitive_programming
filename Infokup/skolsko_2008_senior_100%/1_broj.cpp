#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

string even;
string odd;
string s;
string sol1;
string sol2;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> s;
	for(int i=0;i<s.length();i++) {
		if((s[i]-'0')%2) odd += s[i];
		if((s[i]-'0')%2==0) even += s[i];		
	}
	sort(even.begin(),even.end(),greater<char>()); 
	sort(odd.begin(),odd.end(),greater<char>());
	for(int i=0;i<min(odd.size(),even.size());i++) {
		sol1 += odd[i];
		sol1 += even[i];
	}
	for(int i=0;i<min(odd.size(),even.size());i++) {
		sol2 += even[i];
		sol2 += odd[i];
	}
	if((sol1[sol1.size()-1]-'0')%2) {
		if(even.size()>odd.size()) sol1 += even[odd.size()];
	}
	else if((sol1[sol1.size()-1]-'0')%2==0) {
		if(odd.size()>even.size()) sol1 += odd[even.size()];
	}
	if((sol2[sol2.size()-1]-'0')%2) {
		if(even.size()>odd.size()) sol2 += even[odd.size()];
	}
	else if((sol2[sol2.size()-1]-'0')%2==0) {
		if(odd.size()>even.size()) sol2 += odd[even.size()];
	}
	if(sol1.size()==sol2.size()) {
		if(sol1[0]>sol2[0]) cout << sol1;
		else cout << sol2;
	}
	else if(sol1.size()>sol2.size()) cout << sol1;
	else cout << sol2;
	return 0;
}
