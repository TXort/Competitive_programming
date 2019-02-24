#include<iostream>

using namespace std;

int main() {
	int k, n; int sum = 0;
	cin >> k >> n;
	for(int i=1;i<n;i++) sum += i;
	cout << k-sum << endl;
	for(int i=1;i<n;i++) cout << i << endl;
	return 0;
}
