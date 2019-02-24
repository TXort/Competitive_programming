#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

vector<int> a(10001), b(10001);

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	ll maxsum, suma, sumb; int n, m; int it1, it2 = 0;
	while(1) {
		maxsum=suma=sumb=0; n=m=0; it1=it2=0;
		cin >> n;
		if(!n) break;
		for(int i=0;i<n;i++) cin >> a[i];
		cin >> m;
		for(int i=0;i<m;i++) cin >> b[i];
		while(it1 < n or it2 < m) {
			suma = 0; sumb = 0;
			while(it1 < n) {
				suma += a[it1]; it1 += 1;
				if(binary_search(b.begin(),b.begin()+m,a[it1-1])) break;
			}
			while(it2 < m) {
				sumb += b[it2]; it2 += 1;
				if(binary_search(a.begin(),a.begin()+n,b[it2-1])) break;
			}
			if(suma>sumb) maxsum += suma;
			else maxsum += sumb;
		}
		cout << maxsum << "\n";
		fill(a.begin(), a.begin()+n, 0);
		fill(b.begin(), b.begin()+m, 0);
	}
	return 0;
}
