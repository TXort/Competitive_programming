#include<iostream>
#include<string>

using namespace std;

string mat[4];

int main() {
	for(int i=0;i<4;i++) cin >> mat[i];
	for(int i=0;i<12;i++)
		for(int j=0;j<4;j++)
			if(mat[j][i]=='0') cout << j+1 << "\n";
	return 0;
}
