#include<iostream>

using namespace std;

int ar,br,cr,dr,al,bl,cl,dl,qr,wr,er,rr,ql,wl,el,rl,sum;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> ar >> br >> cr >> dr >> al >> bl >> cl >> dl >> sum;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++)
				for(int l=0;l<10;l++)
					if(i+j+k+l==sum) {
						qr = wr = er = ql = wl = el = 0;
						if(i>j) qr++;
						if(i>k) qr++;
						if(i>l) qr++;
						if(j>k) wr++;
						if(j>l) wr++;
						if(k>l) er++;
						if(l>k) ql++;
						if(l>j) ql++;
						if(l>i) ql++;
						if(k>j) wl++;
						if(k>i) wl++;
						if(j>i) el++;
						if(qr==ar && wr==br && er==cr && ql==dl && wl==cl && el==bl) {
							cout << i << j << k << l;
							cout << "\n";
						}
					}
	return 0;
}
