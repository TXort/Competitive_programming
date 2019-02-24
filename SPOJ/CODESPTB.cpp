#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void fs(int &x) {
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


int bit[1000005];
int arr[1000001];

int n;

int sum(int k) {
	int s = 0;
	while (k >= 1) {
		s += bit[k];
		k -= k&-k;
	}
	return s;
}

void add(int k, int x) {
	while(k <= n) {
		bit[k] += x;
		k += k&-k;
	}
}

void convert()  { 
    int temp[n]; 
    for (int i=0; i<n; i++) 
        temp[i] = arr[i]; 
    sort(temp, temp+n); 
    for (int i=0; i<n; i++) { 
        arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1; 
    } 
} 

int getInvCount() { 
    int invcount = 0;  
    convert(); 
    int BIT[n+1]; 
    for (int i=1; i<=n; i++) 
        BIT[i] = 0; 
    for (int i=n-1; i>=0; i--) { 
        invcount += sum(arr[i]-1); 
        add(arr[i], 1); 
    } 
    return invcount; 
}

int main() {
	int t;
	fs(t);
	while(t--) {
		fs(n);
		for(int i=0;i<n;i++) fs(arr[i]);
		printf("%d\n", getInvCount());
		memset(arr, 0, sizeof(arr));
		memset(bit, 0, sizeof(bit));
	}
	return 0;
}

