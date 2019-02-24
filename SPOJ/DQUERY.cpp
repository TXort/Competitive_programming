#include <bits/stdc++.h> 
using namespace std; 

const int MAX = 1000000; 
  
int arr[MAX];
int freq[MAX];
int block;
  
struct Query { 
    int L, R, index, result; 
};

bool compare(Query x, Query y)  { 
    if (x.L / block != y.L / block) 
        return x.L / block < y.L / block; 
    return x.R < y.R; 
} 

bool compare1(Query x, Query y) { 
    return x.index < y.index; 
} 

Query questions[200004];

void queryResults(int n, int q) { 
    block = (int)sqrt(n); 
    sort(questions, questions + q, compare); 
    int currL = 0, currR = 0; 
    int curr_Diff_elements = 0; 
    for (int i = 0; i < q; i++) { 
        int L = questions[i].L, R = questions[i].R; 
        while (currL < L) { 
            freq[arr[currL]]--; 
            if (freq[arr[currL]] == 0) curr_Diff_elements--;  
            currL++; 
        } 
        while (currL > L) { 
            freq[arr[currL - 1]]++; 
            if (freq[arr[currL - 1]] == 1)  
                curr_Diff_elements++;  
            currL--; 
        } 
        while (currR <= R) { 
            freq[arr[currR]]++; 
            if (freq[arr[currR]] == 1)  
                curr_Diff_elements++; 
            currR++; 
        } 
        while (currR > R + 1) { 
            freq[arr[currR - 1]]--; 
            if (freq[arr[currR - 1]] == 0) curr_Diff_elements--; 
            currR--; 
        } 
        questions[i].result = curr_Diff_elements; 
    }
}
  
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n, q;
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	cin >> q;
	for(int i=0;i<q;i++) {
		cin >> questions[i].L >> questions[i].R;
		questions[i].L--; questions[i].R--;
		questions[i].index = i; questions[i].result = 0;
	}
	queryResults(n, q); 
    sort(questions, questions + q, compare1); 
    for (int i=0;i<q;i++) cout << questions[i].result << "\n"; 
    return 0; 
} 


