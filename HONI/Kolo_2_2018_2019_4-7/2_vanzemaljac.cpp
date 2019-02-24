#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);
  	int n, m, k;
  	cin >> n;
  	if(n>=6 && n<=10) {
  		cout << "D" << "\n";
  		cout << "D" << "\n";
	}
	else if(n>=12 && n<=16) {
		cout << "N" << "\n";
  		cout << "R" << "\n";
	}
	else if(n>=18 && n<=21) {
		cout << "N" << "\n";
		cout << "V" << "\n";
	}
	else {
		cout << "N" << "\n";
		cout << "N" << "\n";
	}
	return 0;
}
