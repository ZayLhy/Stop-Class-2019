// luogu-judger-enable-o2
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[2000010];
int dp[2000010];
int n,T;
int ans;
void init(){
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	ans=0;
	dp[0]=1; 
}
void work(){
	init(); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(!dp[a[i]]){
			ans++;
		}
		for(int j=a[i];j<=a[n];j++){
			dp[j]+=dp[j-a[i]];
		}
	}
	printf("%d\n",ans);
	return ;
} 
int main(){
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		work();
	}
	return 0;
}
