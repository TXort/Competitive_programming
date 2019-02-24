#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,m; cin >> n; cin >> m;
	vector<string> unos(m);
	for(int i=0;i<n;i++) cin >> unos[i];
	vector<short> pomocni(m);
	vector<vector<short> > lijevo(m,pomocni);
	vector<vector<short> > desno(m,pomocni);
	for(int i=0;i<n;i++) {
		int zadnji = 0;
		for(int j=0;j<m;j++) {
			if(unos[i][j]=='*') zadnji = 0;
			lijevo[i][j] = zadnji;
		}
		zadnji = 0;
		for(int j=m-1;j>=0;j--) {
			zadnji++;
			if(unos[i][j]=='*') zadnji = 0;
			desno[i][j] = zadnji;
		}
	}
	int rjesenje = 0;
	for(int j=0;j<n;j++) {
		int zadnji=0,moguLijevo=1000,moguDesno=1000;
		for(int i=0;i<m;i++) {
			zadnji++;
			moguLijevo=min(moguLijevo,(int)lijevo[i][j]);
			moguDesno=min(moguDesno,(int)desno[i][j]);
			if(unos[i][j]=='*') {
				zadnji=0;
				moguLijevo=moguDesno=1000;
			}
			rjesenje=max(rjesenje,zadnji*(moguLijevo+moguDesno-1));
		}
	}
	cout << rjesenje << "\n";
	return 0;
}
