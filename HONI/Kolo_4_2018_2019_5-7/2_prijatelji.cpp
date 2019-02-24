#include<iostream>
#include<vector>

using namespace std;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    vector<int> a(4);
    int maks = 0; int pos = -1;
    for(int i=0;i<3;i++) {
    	cin >> a[i];
    	if(a[i]>maks) {
    		maks = a[i];
    		pos = i;
		}
	}
    if(pos==0) cout << "lijevi prijatelj";
    if(pos==1) cout << "prijatelj u sredini";
    if(pos==2) cout << "desni prijatelj";
    return 0;
}
