#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int a,b,aa,bb;
int gcd(int a,int b){
	while(b!=0){
		int t=a;
		a=b;
		b=t%a;
	}
	return a;
}
int solve(int a,int aa,int b,int bb){
	int ans=0;
	int j=a/aa,k=bb/b;
	for(int i=1;i*i<=bb;i++){
		if(bb%i==0){
			if(i%aa==0){
				if(gcd(i/aa,j)==1){
					if(gcd(k,bb/i)==1){
						ans++;
					}
				}
			}
			int ii=bb/i;
			if(ii==i){
				continue;
			}
			if(ii%aa==0){
				if(gcd(ii/aa,j)==1){
					if(gcd(k,bb/ii)==1){
						ans++;
					}
				}
			}
		}
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&a,&aa,&b,&bb);
		printf("%d\n",solve(a,aa,b,bb));
	}
	return 0;
}
