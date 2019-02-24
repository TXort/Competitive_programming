#include<iostream>
#include<cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long digits, number, k;
    long long n = 0;
    cin >> digits >> number >> k;
    n = number / pow(10, digits-k); n++;
    n = n*pow(10, digits-k);
    cout << n-number-1;
    return 0;
}
