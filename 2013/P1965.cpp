#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k,x;
long long kasumi(long long a,long long b){
	if(b==0){
		return 1%n;
	}
    long long ans=1,basic=a;
    while(b){
        if(b&1) ans=ans*basic%n;
        basic=basic*basic%n;
        b>>=1;
    }
    return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&x);
	printf("%lld",(x%n+m%n*kasumi(10,k)%n)%n);
	return 0;
}
