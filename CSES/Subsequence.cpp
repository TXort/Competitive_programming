#include<iostream>
#include<vector> 
#include<algorithm> 
#include<cmath> 
#include<set> 

using namespace std; 
set<char> a; 

int main() { 	
    string s; string sol; 
    cin >> s; 	
    for(int i=0;i<s.size();i++) { 		
        a.insert(s[i]); 		
        if(a.size()==4) { 			
            sol.push_back(s[i]); 
            a.clear(); 
		} 	
    } 	
	if(find(a.begin(),a.end(),'A')==a.end()) sol.push_back('A'); 	
	else if(find(a.begin(),a.end(),'C')==a.end()) sol.push_back('C'); 	
	else if(find(a.begin(),a.end(),'G')==a.end()) sol.push_back('G'); 	
	else sol.push_back('T'); 
    cout << sol << " "; 	
	return 0;
}
