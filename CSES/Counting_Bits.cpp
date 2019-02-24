#include <cmath>
#include <iostream>
#include <map>
#define ull unsigned long long int
using namespace std;
 
map<ull, ull> mapa;
 
ull solve(ull n) {
	if (n == 0) return 0;
	if (mapa[n]) return mapa[n];
	ull z = n;
	ull a = 1;
	while (z >>= 1) a <<= 1;
	a -= 1;
	ull b = n - a;
	mapa[n] = solve(a)+b+solve(b-1);
	return mapa[n];
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ull n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
