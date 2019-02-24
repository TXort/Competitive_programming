#include<iostream>

using namespace std;

int n, t;
int d[3000];
int r, s;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> n >> t;
	for(int i=0;i<t;i++) cin >> d[i];
	cin >> r >> s; r--; s--;
	for(int i=t-1;i>=0;--i) {
      	int r0 = r - r%d[i];
      	int s0 = s - s%d[i];
      	int dr = r - r0;
      	int ds = s - s0;
      	r = r0 + d[i]-ds-1;
      	s = s0 + dr;
  	}
   	cout << r*n+s+1;
	return 0;
}
