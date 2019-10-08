#include<cstdio>
#include<algorithm>
int a[1000010<<1];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]) ans+=(a[i]-a[i-1]);
	}
	printf("%d",ans);
	return 0;
}
