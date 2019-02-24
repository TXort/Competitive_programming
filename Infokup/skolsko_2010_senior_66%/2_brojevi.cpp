#include <iostream>

using namespace std;

#define MAXN 100000
#define MAXK 300000

int N, K;
char potezi[MAXK+1];
typedef long long llint;

struct diagonala {
    int r0;
    llint x;
    char dx;
    llint get( int r ) { return x + dx*(r-r0); }
} A[2*MAXN];

int main( void ) {
    cin >> N >> K >> potezi;

    llint next = 1;
    for( int i = 0; i < 2*N-1; ++i ) {
        int size = i < N ? i+1 : 2*N-i-1;
        A[i].r0 =  i < N ?  1  : i-N+2;
        if( i%2 ) {
            A[i].x = next;
            A[i].dx = 1;
        } else {
            A[i].x = next + size - 1;
            A[i].dx = -1;
        }
        next += size;
    }
    
    int r = 0, c = 0;
    llint ret = 1;
    for( int i = 0; i < K; ++i ) {
        if( potezi[i] == 'U' ) --r;
        if( potezi[i] == 'D' ) ++r;
        if( potezi[i] == 'L' ) --c;
        if( potezi[i] == 'R' ) ++c;
        ret += A[r+c].get(r);
    }
    cout << ret << endl;

    return 0;
}
