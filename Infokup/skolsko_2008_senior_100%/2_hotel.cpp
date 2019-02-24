#include<algorithm>
#include<iostream>

using namespace std;

int L, H, K;
int visina[3000];

int main() {
	cin >> L >> H >> K;
	for(int i=0;i<L;i++) cin >> visina[i];
	int sol = L*H;
	for( int i=0;i+K<=L;i++) {
      	int najniza = H - K;
      	int suma = 0;
      	for(int j=0;j<K;j++) {
        	najniza = min( najniza, visina[i+j] );
         	suma += visina[i+j];
     	}
      sol = min(sol,suma-najniza*K);
  	}
   	cout << sol;
	return 0;
}
