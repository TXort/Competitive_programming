#include<algorithm>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

string times;
int ttime, start_number;
bool neg = false;
vector<string> timevector;
vector<string> stringvector;
vector<int> num;

string add_time(string s) {
	int next = 0;
	for(int i=s.size()-1;i>=0;i--) {
		if(s[i]==':' || s[i]==',') continue;
		if(i!=6 && i!=3) {
			int num = (s[i]-'0')+(times[i]-'0')+next;
			next = 0;
			if(num>9) {
				s[i] = (num%10)+'0';
				next = num / 10;
			}
			else s[i] = num+'0';
		}
		else {
			int num = (s[i]-'0')+(times[i]-'0')+next;
			next = 0;
			if(num>5) {
				s[i] = (num%6)+'0';
				next = num / 6;
			}
			else s[i] = num+'0';
		}
	}
	return s;
}

string remove_time(string s) {
	int next = 0;
	for(int i=s.size()-1;i>=0;i--) {
		if(s[i]==':' || s[i]==',') continue;
		if(i!=6 && i!=3) {
			int num = 0;
			if(s[i]<times[i]+next) {
				num = 10 + (s[i]-'0') - (times[i]-'0') - next;
				next = 1;
				s[i] = num + '0';
			}
			else {
				s[i] = ((s[i]-'0') - (times[i]-'0')-next)  + '0';
				next = 0;
			}
		}
		else {
			int num = 0;
			if(s[i]<times[i]+next) {
				num = 6 + (s[i]-'0') - (times[i]-'0') - next;
				next = 1;
				s[i] = num + '0';
			}
			else {
				s[i] = ((s[i]-'0') - (times[i]-'0')-next)  + '0';
				next = 0;
			}
		}
	}
	return s;
}

string change_time(string s) {
	string z = " --> ";
	string s1 = s.substr(0, 12);
	string s2 = s.substr(17, 28);
	if(!neg) {
		s1 = add_time(s1);
		s2 = add_time(s2);
	}
	else {
		s1 = remove_time(s1);
		s2 = remove_time(s2);
	}
	return s1+z+s2;
}

void convert_time_to_string(int x) {
    if(x<0) {
    	neg = 1;
    	x *= -1;
	}
	while(x) {
		times.push_back((x%10) + '0');
		x /= 10;
		if(times.size()==3 && x!=0) times += ',';
		else if(times.size()==6 && x!=0) times += ':';
		else if(times.size()==9 && x!=0) times += ':';
	}
	while(times.size()!=12) {
		times += '0';
		if(times.size()==3) times += ',';
		else if(times.size()==6) times += ':';
		else if(times.size()==9) times += ':';
	}
	reverse(times.begin(),times.end());
}

void get_input() {
    string s;
    getline(cin, s);
    start_number = stoi(s);
    while(1) {
    	if(s[0]=='#') break;
    	getline(cin, s);
    	timevector.push_back(s);
    	int cnt = 0;
    	do {
    		getline(cin, s);
    		if(s.length()==0) continue;
    		if(isdigit(s[0]) || s[0]=='#') break;
			stringvector.push_back(s);
			cnt++;
		} while(!isdigit(s[0]) && s[0]!='#');
		if(s.length()!=0) num.push_back(cnt);
		if(s[0]=='#') break;
	}
	cin >> ttime;
	if(ttime<0) {
		ttime *= -1;
		neg = true;
	}
}

void output() {
	int x = 0;
	for(int i=0;i<timevector.size();i++) {
		cout << start_number << "\n";
		cout << change_time(timevector[i]) << "\n";
		int cnt = num[i];
		while(cnt--) {
			cout << stringvector[x] << "\n";
			x++;
		}
		if(i!=timevector.size()-1 ) cout << "\n";
		start_number++;
	}
	cout << "#";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    get_input();
    convert_time_to_string(ttime);
   	output();
    return 0;
}
