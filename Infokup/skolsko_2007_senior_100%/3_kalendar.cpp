#include<iostream>
#include<string>

using namespace std;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n, x, y; string s;
	cin >> n >> s;
	if(s=="ponedjeljak") x = 0;
	else if(s=="utorak") x = 1;
	else if(s=="srijeda") x = 2;
	else if(s=="cetvrtak") x = 3;
	else if(s=="petak") x = 4;
	else if(s=="subota") x = 5;
	else if(s=="nedjelja") x = 6;
	cout << (x+6)-((n+x-1)%7);
 	return 0;
}

