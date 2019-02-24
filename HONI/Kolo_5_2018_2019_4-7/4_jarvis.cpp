#include<iostream>

using namespace std;

int a[100005], b[100005], freqpos[2000005], freqneg[2000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) {
    	if(a[i]>=b[i]) freqpos[a[i]-b[i]]++;
    	else freqneg[b[i]-a[i]]++;
	}
	int sol = 0;
	for(int i=0;i<2000004;i++) sol = max(sol, freqpos[i]);
 	for(int i=0;i<2000004;i++) sol = max(sol, freqneg[i]); 
	cout << sol;
    return 0;
}
