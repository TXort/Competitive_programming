#include<iostream>
#include<string>

using namespace std;

bool arr[35];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	string s;
	cin >> s;
	int n; cin >> n;
	int x;
	while(n--) {
		cin >> x;
		arr[x-1] = 1;
	}
	int s1 = 0, s2 = 0;
	for(int i=0;i<30;i++) {
		if(s=="sub") s1++;
		else if(s=="ned") s1++;
		else if(arr[i]) s2++;
		else if(i%2) s1++;
		else s2++;
		if(s=="pon") s = "uto";
		else if(s=="uto") s = "sri";
		else if(s=="sri") s = "cet";
		else if(s=="cet") s = "pet";
		else if(s=="pet") s = "sub";
		else if(s=="sub") s = "ned";
		else if(s=="ned") s = "pon";
	}
	cout << s1 << " " << s2;
	return 0;
}
