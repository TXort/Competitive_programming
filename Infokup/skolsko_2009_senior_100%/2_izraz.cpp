#include <bits/stdc++.h> 
using namespace std; 
  
int precedence(char op){ 
    if(op == '+'||op == '-') return 1; 
    if(op == '*'||op == '/') return 2; 
    return 0; 
} 
  
int applyOp(int a, int b, char op){ 
    switch(op){ 
        case '+': return a + b; 
        case '-': return a - b; 
        case '*': return a * b; 
        case '/': return a / b; 
    } 
} 
  
int evaluate(string tokens){  
    stack<int> values; 
    stack<char> ops; 
    for(int i=0;i<tokens.length();i++) { 
        if(tokens[i] == ' ') continue; 
        else if(tokens[i] == '(') ops.push(tokens[i]); 
        else if(isdigit(tokens[i])) { 
            int val = 0; 
            while(i<tokens.length() && isdigit(tokens[i])) { 
                val = (val*10)+(tokens[i]-'0'); 
                i++; 
            }
            values.push(val); 
        } 
        else if(tokens[i] == ')') { 
            while(!ops.empty() && ops.top() != '(') { 
                int val2 = values.top(); 
                values.pop(); 
                int val1 = values.top(); 
                values.pop(); 
                char op = ops.top(); 
                ops.pop(); 
                values.push(applyOp(val1, val2, op)); 
            } 
            ops.pop(); 
        }
        else { 
            while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) { 
                int val2 = values.top(); 
                values.pop(); 
                int val1 = values.top(); 
                values.pop(); 
                char op = ops.top(); 
                ops.pop(); 
                values.push(applyOp(val1, val2, op)); 
            }
            ops.push(tokens[i]); 
        } 
    } 
    while(!ops.empty()){ 
        int val2 = values.top(); 
        values.pop(); 
        int val1 = values.top(); 
        values.pop();   
        char op = ops.top(); 
        ops.pop();   
        values.push(applyOp(val1, val2, op)); 
    }
    return values.top(); 
}

int main() { 
    string s, r;
    cin >> s;
    int it = 0;
    while(it<s.size()) {
    	while(isdigit(s[it]) && it!=s.size()-1) {
    		r += s[it];
    		it++;
		}
		r += ' ';
    	r += s[it];
    	r += ' ';
    	it++;
	}
	int sol = -1000000000;
	int val;
    for(int i=0;i<r.length();i++) {
    	if(r[i]=='+' || r[i]=='-') {
    		if(r[i]=='+') r[i] = '-';
    		else if(r[i]=='-') r[i] = '+';
    		val = evaluate(r);
    		if(val>sol) {
    			sol = val;
    			s = r;
			}
     		if(r[i]=='+') r[i] = '-';
    		else if(r[i]=='-') r[i] = '+';   		
		}
	}
	for(int i=0;i<s.length();i++) {
		if(s[i]==' ') continue;
		cout << s[i];
	}
	cout << "\n";
	cout << sol;
    return 0; 
}
