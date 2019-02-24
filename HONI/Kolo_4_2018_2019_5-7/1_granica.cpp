#include<iostream>

using namespace std;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    int n,m,k;
    cin >> n >> m >> k;
    if(n+m+k>=10) cout << 1;
    else cout << 0;
    return 0;
}
