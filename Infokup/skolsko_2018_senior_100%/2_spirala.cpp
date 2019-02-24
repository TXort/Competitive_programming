#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int arr[105][105];

int main() {
    string s; cin >> s;
    int high = s.size()/2;
    int m = 1000; int a, b;
    bool found = 0;
    for(int i=2;i<=high;i++)
        for(int j=high;j>=0;j--)
           if(i*j==s.size() && abs(i-j)<m) {
              a=i; b=j; int x = abs(i-j);
              m = min(m,x); found = 1;
           }
    if(!found) {
    	cout << s;
    	return 0;
	}
    if(b<a) swap(a,b);
    int t=0, x=-1, y=0;
    while(t<a*b) {
        while(arr[y][x+1]==0 && x<b-1) {
           x++; t++; arr[y][x] = t;
        }
        while(arr[y+1][x]==0 && y<a-1) {
           y++; t++; arr[y][x] = t;
        }
        while(arr[y][x-1]==0 && x>0) {
           x--; t++; arr[y][x] = t;
        }
        while(arr[y-1][x]==0 && y>0) {
           y--; t++; arr[y][x] = t;
        }
    }
    for(int i=0;i<a;i++) {
        for(int j=0;j<b;j++)
        	cout << s[arr[i][j]-1];
		cout << "\n";
	}
    return 0;
}
