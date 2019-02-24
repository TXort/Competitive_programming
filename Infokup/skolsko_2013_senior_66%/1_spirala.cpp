#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int arr[105][105];

int main() {
    int n;
    cin >> n;
    int t=0, x=0, y=-1;
    while(t<n*n) {
        while(arr[y+1][x]==0 && y<n-1) {
           y++; t++; arr[y][x] = t;
        }
        while(arr[y][x+1]==0 && x<n-1) {
           x++; t++; arr[y][x] = t;
        }
        while(arr[y-1][x]==0 && y>0) {
           y--; t++; arr[y][x] = t;
        }
        while(arr[y][x-1]==0 && x>0) {
           x--; t++; arr[y][x] = t;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
        	cout << arr[i][j] << " ";
		cout << "\n";
	}
    return 0;
}
