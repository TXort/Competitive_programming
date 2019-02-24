#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
#define MAX 100000

using namespace std;

void fastscan(ll &x) {
        bool neg=false;
        register int c;
        x =0;
        c=getchar();
        if(c=='-')
        {
            neg = true;
            c=getchar();
        }
        for(;(c>47 && c<58);c=getchar())
            x = (x<<1) + (x<<3) +c -48;
        if(neg)
            x *=-1;
}

ll arr[MAX+10];
ll dif[MAX+10];

int main() {
	ll t; fastscan(t);
	while(t--) {
		ll n, u;
		fastscan(n); fastscan(u);
		while(u--) {
			ll l, r, val;
			fastscan(l); fastscan(r); fastscan(val);
			dif[l] += val;
			dif[r+1] -= val;
		}
		arr[0] = dif[0];
		for(int i=1;i<=n;i++) {
			arr[i] = arr[i-1] + dif[i];
		}
		ll q; fastscan(q);
		while(q--) {
			ll index; fastscan(index);
			printf("%d\n", arr[index]);
		}
		memset(arr, 0, sizeof(arr));
		memset(dif, 0, sizeof(dif));
	}
	return 0;
}
