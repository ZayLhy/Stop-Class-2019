#include<cstdio>
int a[10005],b[10005],g[10005],k[10005];
int main(){
	int n;
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&a[i],&b[i],&g[i],&k[i]);
	}
	scanf("%d%d",&x,&y);
	for(int i=n;i>=1;i--){
		if(x>=a[i]&&x<=(a[i]+g[i])){
			if(y>=b[i]&&y<=(b[i]+k[i])){
				printf("%d",i);
				return 0;
			}
		}
	}
	printf("-1");
	return 0;
} 
