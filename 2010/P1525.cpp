#include<cstdio>
#include<algorithm>
using namespace std; 
const int MAXN = 400000 + 10;
int n,m;
int fa[MAXN],fb[MAXN];
struct Node{
	int a;
	int b;
	int c;
	bool operator <(const Node &x)const{
		return c>x.c; 
	} 
}data[MAXN<<1];
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	} 
	return ;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]); 
} 
void merge(int x,int y){
	fa[find(fa[x])]=find(fa[y]); 
} 
bool check(int x,int y){
	return find(x)==find(y); 
} 
int main(){
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&data[i].a,&data[i].b,&data[i].c);
	}
	sort(data+1,data+m+1);
	for(int i=1;i<=m+1;i++){
		if(check(data[i].a,data[i].b)){
			printf("%d",data[i].c); 
			return 0; 
		} 
		if(!fb[data[i].a]){
			fb[data[i].a]=data[i].b; 
		} 
		else{
			merge(fb[data[i].a],data[i].b);
		}
		if(!fb[data[i].b]){
			fb[data[i].b]=data[i].a; 
		} 
		else{
			merge(fb[data[i].b],data[i].a);
		} 
	} 
	return 0;
} 
