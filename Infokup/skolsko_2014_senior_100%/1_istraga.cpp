#include<iostream>
#include<vector>

using namespace std;

int func(int x) {
	int var = x; int mp = 1;
	while(x) {
		int digit = x % 10;
		x /= 10;
		digit==0?mp*=1:mp*=digit;
	}
	return var+mp;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int f, s, n;
	cin >> f >> s >> n;
	vector<int> a(n+2,0);
	a[0] = f; a[1] = s;
	for(int i=2;i<a.size();i++) a[i] = func(a[i-1]) + func(a[i-2]);
	for(int i=2;i<a.size();i++) cout << a[i] << " ";
	return 0;
}
