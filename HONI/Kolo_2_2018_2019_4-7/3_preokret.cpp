#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);
  	int a, b;
  	int pola = 1440;
  	int gol = 0;
  	cin >> a;
  	vector<int> tima(a);
  	for(int i=0;i<a;i++) {
  		cin >> tima[i];
  		if(tima[i]<=pola) gol++;
	  }
  	cin >> b;
  	vector<int> timb(b);
  	for(int i=0;i<b;i++){
  		cin >> timb[i];
  		if(timb[i]<=pola) gol++;
	  }
	int tr = a+b;
	int gola = 0,golb = 0;
	int sol = 0;
	int vara = 0, varb = 0;
	if(tima[0]<timb[0]) {
		gola++; vara++;
	}
	else {
		golb++; varb++;
	}
	bool ona = 1; bool onb = 1;
	int proslia = 0, proslib = 0;
	for(int i=0;i<tr;i++) {
		if(vara>=a) ona = 0;
		if(varb>=b) onb = 0;
		if(gola==golb) {
			if(tima[vara]<timb[varb] && ona) {
				vara++; gola++;
				if(proslia<proslib) sol++;
			}
			else if(tima[vara]>timb[varb] && onb) {
				varb++; golb++;
				if(proslia>proslib) sol++;
			}
			continue;
		}
		proslia = gola; proslib = golb;
		if(tima[vara]<timb[varb] && ona) {
			vara++; gola++;
		}
		else if(tima[vara]>timb[varb] && onb) {
			varb++; golb++;
		}
	}
	cout << gol << "\n" << sol;
	return 0;
}
