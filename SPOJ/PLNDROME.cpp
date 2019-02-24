#include <iostream>

char arr[100005];

int main() {
	int tests;
    scanf("%d", &tests);
    for (int t=1;t<=tests;t++) {
    	int n, q;
        scanf("%d", &n);
        scanf(" %s", arr);
        scanf("%d", &q);
        
        int dif = 0;
        for (int i = 0; i + i < n; i ++)
            if (arr[i] != arr[n - 1 - i]) dif++;
        printf("Case %d:\n", t);

        while (q--) {
            int pos; char c;
            scanf("%d %c", &pos, &c);
            pos--;
            if (arr[pos] == arr[n - 1 - pos] && pos != n - 1 - pos && arr[pos] != c) dif++;
            else if (arr[pos] != arr[n - 1 - pos] && arr[n - 1 - pos] == c) dif--;
            arr[pos] = c;
            if (dif == 0) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
