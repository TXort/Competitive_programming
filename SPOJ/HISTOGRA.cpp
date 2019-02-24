#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
  while(404) {
  	int n;
  	cin >> n;
  	if(n==0) break;
  	vector<int> a(n);
  	for(int i=0; i<n; i++) cin >> a[i];
  	stack<int> s;
  	long long int ma = 0, tp, awt, i = 0;
  	while(i<n) {
    	if(s.empty()||a[s.top()]<=a[i])
        	s.push(i++);
    	else {
      	tp = s.top();
      	s.pop();
      	awt = a[tp]*(s.empty() ? i : i-s.top()-1);
      	if(ma<awt) ma=awt;
    	}
  	}
  	while(!s.empty()) {
    	tp = s.top();
    	s.pop();
    	awt = a[tp]*(s.empty() ? i : i-s.top()-1);
      	if(ma<awt) ma=awt;
  	}
  	cout << ma << "\n";
  }
  return 0;
 }

