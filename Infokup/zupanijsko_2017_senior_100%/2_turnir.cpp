#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<vector<int> > tur;
vector<vector<int> > soltur;
int count[1050];

int main() {
	int n;
	cin >> n; n++;
	vector<int> a;
	tur.insert(tur.begin(),n,a);
	soltur.insert(soltur.begin(),n,a);
	for(int i=0;i<n;i++)
		for(int j=0;j<pow(2,i);j++) {
			int x; cin >> x; count[x]++;
			tur[i].push_back(x);
		}
	soltur[n-1] = tur[n-1];
	for(int i=soltur.size()-1;i>=1;i--)
		for(int j=0;j<soltur[i].size()-1;j+=2)
			soltur[i-1].push_back(count[soltur[i][j]]>count[soltur[i][j+1]]?soltur[i][j]:soltur[i][j+1]);
	for(int i=0;i<n;i++) {
		for(int j=0;j<soltur[i].size();j++) {
			cout << soltur[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
