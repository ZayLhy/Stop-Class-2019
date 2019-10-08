#include<cstdio>
#define int long long
int x,y,ans;
void exgcd(int a,int b){
	if(b==0){
		x=1;
		y=0;
		return ;
	}
	exgcd(b,a%b);
	int cache=x;
	x=y;
	y=cache - a / b * y;
}
signed main(){
	int a,b;
	scanf("%lld%lld",&a,&b);
	exgcd(a,b);
	ans=x;
	ans=(ans%b+b)%b;
	printf("%lld",ans);
	return 0;
}
