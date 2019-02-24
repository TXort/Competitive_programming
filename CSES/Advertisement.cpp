#include<iostream>
#include<stack>
#include<vector>
 
using namespace std;
 
int main() {
 	int n;
 	scanf("%d", &n);
  	vector<int> a(n);
 	for(int i=0; i<n; i++) scanf("%d", &a[i]);
  	stack<int> s;
 	long long int ma = 0, tp, awt, i = 0;
 	while(i<n) {
    	if(s.empty()||a[s.top()]<=a[i]) s.push(i++);
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
  	printf("%lld", ma);
  	return 0;
}
