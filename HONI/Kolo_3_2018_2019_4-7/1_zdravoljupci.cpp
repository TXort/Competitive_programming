#include<iostream>
 
using namespace std; 

int main() {
	int n, x, y;
	cin >> n >> x >> y;
	n = n - (x+y);
	if(n<0) n = 0;
	cout << n;
    return 0;
}
