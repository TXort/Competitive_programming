#include<iostream>
#include<algorithm>
int a[200002];
int b[200002];
using namespace std;
int main() {
    int n, m, k; int sol = 0;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<m;i++) scanf("%d", &b[i]);
    sort(a, a+n); sort(b, b+m);
	int i = 0;
	int j = 0;
	while(i<n && j<m)
		if(a[i]+k<b[j]) i++;
		else if(a[i]-k>b[j]) j++;
		else{i++;j++;sol++;}
    printf("%d", sol);
    return 0;
}
