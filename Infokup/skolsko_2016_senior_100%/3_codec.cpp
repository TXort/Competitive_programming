#include<iostream>
#include<algorithm>

using namespace std;

int ii[102];
int pe[102];
int be[102];
int org[102];

void reversed(int arr[], int start, int end) { 
    while (start<end) { 
        swap(arr[start],arr[end]);
        start++; 
        end--; 
    }  
}      

int operations(int num) {
	int var = 1;
	if(num<0) {num*=-1; var++;}
	if(num<10) return var+1;
   	if(num<100) return var+2;
   	if(num<1000) return var+3;
   	if(num<10000) return var+4;
   	if(num<100000) return var+5;
   	if(num<1000000) return var+6;
   	if(num<10000000) return var+7;
   	if(num<100000000) return var+8;
   	if(num<1000000000) return var+9;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n; cin >> n;
	for(int i=0;i<n;i++) cin >> org[i];
	for(int i=0;i<n;i++) ii[i] = operations(org[i]);
	for(int i=1;i<n-1;i++) pe[i] = operations(org[i]-org[i-1]);
	for(int i=1;i<n-1;i++) be[i] = operations(org[i]-org[i+1]);
	int sol = 0;
	bool exception = 0;
	reversed(ii,0,n-1);
	reversed(pe,0,n-1);
	reversed(be,0,n-1);
	sol += ii[0] + ii[n-1];
	for(int i=1;i<n-1;i++) {
		if(exception) {
			if(ii[i]<=pe[i]) {
				sol += ii[i]; exception = 0;
			}
			else sol += pe[i];
			continue;
		}		
		if(pe[i]<ii[i] && pe[i]<be[i]) {
			exception = 1;
			sol += pe[i];
		}
		else sol += min(ii[i],be[i]);
	}
	cout << sol;
	return 0;
}
