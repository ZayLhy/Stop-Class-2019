#include<cstdio>
int a[200<<1];
int b[200<<1];
int sheet[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int main(){
	int n,na,nb;
	int ansa,ansb;
	ansa=ansb=0;
	scanf("%d%d%d",&n,&na,&nb);
	for(int i=0;i<na;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<nb;i++){
		scanf("%d",&b[i]);
	}
	for(int i=0;i<n;i++){
		ansa+=sheet[a[i%na]][b[i%nb]];
		ansb+=sheet[b[i%nb]][a[i%na]];
	}
	printf("%d %d",ansa,ansb);
	return 0;
}
