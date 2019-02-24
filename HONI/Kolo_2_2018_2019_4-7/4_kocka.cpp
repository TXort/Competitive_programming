#include<iostream>
         
using namespace std;
         
int r[100002];
int s[100002];
         
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; bool f = 1; cin >> n;
    for(int i=0;i<4;i++) {
        for(int j=0;j<n;j++) {
            int a;
            cin >> a;
            if(i == 0) {
                if(a == -1) {
                    r[j] = -1;
                    continue;
                }
                r[j] = 1;
                s[a] = 1;
            }
            else if(i == 1) {
                if(a == -1) {
                    if(r[j] == 1) f = 0;
                    continue;
                }
                else if(r[j] == -1 || s[n - a - 1] == -1) f = 0;
                r[j] = 1;
                s[n - a - 1] = 1;
            }
            else if(i == 2) {
                if(a == -1) {
                    if(s[j] == 1) f = 0;
                    continue;
                }
                else if(s[j] == -1 || r[a] == -1) f = 0;
                r[a] = 1;
                s[j] = 1;
            }
            else if(i == 3) {
                if(a == -1) {
                    if(s[j] == 1) f = 0;
                    continue;
                }
                else if(s[j] == -1 || r[n - a - 1] == -1) f = 0;
                r[n - a - 1] = 1;
                s[j] = 1;
            }
        }
    }
    if(f) cout << "DA" << "\n";
    else cout << "NE" << "\n";
    return 0;
}
