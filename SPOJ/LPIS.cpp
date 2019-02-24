#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

 int arr[1000001];
 unordered_map<int, int> um;

int main() {
	int n; scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &arr[i]);
	int sol = 0;
	for(int i=0;i<n;i++) {
		int len = 0;
		
		if (um.find(arr[i]-1) != um.end() &&  len < um[arr[i]-1]) 
            len = um[arr[i]-1];
        
        um[arr[i]] = len + 1;
        
		if (sol < um[arr[i]]) sol = um[arr[i]]; 
	}
	cout << sol;
    return 0;
}

