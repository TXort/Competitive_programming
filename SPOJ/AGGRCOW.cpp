#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>

using namespace std;

int C, N, t; int pos[100000];

int F(int x) {
	int cowsplaced=1,lastpos=pos[0];
	for(int i=1;i<N;i++) {
		if(pos[i]-lastpos>=x) {
			if(++cowsplaced==C) return 1;
			lastpos=pos[i];
		}
	}
	return 0;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &N, &C);
		for(int i=0;i<N;i++) {
			scanf("%d", &pos[i]);
		}
		sort(pos,pos+N);
		int start=0,end=pos[N-1]-pos[0]+1,mid;
		while(end-start>1) {
			mid=(end+start)/2;
			(F(mid)?start:end)=mid;
		}
		printf("%d\n", (start));
	}
	return 0;
}
