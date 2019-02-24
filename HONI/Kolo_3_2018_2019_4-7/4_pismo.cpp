#include<iostream>
#include<vector>
     
using namespace std;
     
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, sol = 1000000000;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=1;i<n;i++) sol = min(max(a[i],a[i-1])-min(a[i],a[i-1]),sol);
    cout << sol;
    return 0;
}
