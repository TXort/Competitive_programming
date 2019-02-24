#include<iostream>
#define ll long long
 
using namespace std;

ll f(ll n) {
    if(n==0) return 0;
    if(n<10) return 1;   
    ll count = 0;     
    ll highest = n;   
    ll weight = 1;     
    while(highest>=10) {
        highest /= 10;
        weight *= 10;
    }
    if(highest==1) count = f(weight-1)+f(n-weight)+n-weight+1;
    else count = highest*f(weight - 1)+f(n-highest*weight)+weight;
    return count;
}
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll n; cin >> n;
	ll low = 0, high = 1e18;
	while(high-low>1) {
		ll mid = (low + high)>>1;
		ll x = f(mid);
		if(x>n) high = mid;
		else low = mid;
	}
	cout << low;
	return 0;
}
