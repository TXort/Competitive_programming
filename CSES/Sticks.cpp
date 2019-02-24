#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
 
using namespace std;
 
int main() {
	int n; scanf("%d", &n);
	unsigned long long int sol = 0;
	vector<int> sticks(n);
	for(int i=0;i<n;i++) scanf("%d", &sticks[i]);
	sort(sticks.begin(),sticks.end());
	int art = sticks[n/2];
	for(int i=0;i<n;i++) sol += abs(art-sticks[i]);
	printf("%d", sol);
    return 0;
}
