#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 500000 + 10;
const int INF = 1000000010;
struct Edge{
	int f;
	int t;
	int v;
	bool operator < (const Edge &b)const{
        return v>b.v;
    }
}a[N],mst[N];
int head[N],nxt[N],tot;
int dep[N],fa[N][21];
int wmax[N][21];
int n,m,q;
bool vis[N];
int lg[N];
struct bcj{
	int fu[N];
	void init(){
		for(int i=1;i<=n;i++){
			fu[i]=i;
		}
		return ;
	}
	int find(int x){
		if(fu[x]==x){
			return x;
		}
		return fu[x]=find(fu[x]);
	}
	bool check(int x,int y){
		return find(x)==find(y);
	}
	void merge(int x,int y){
		x=find(x);
		y=find(y);
		fu[x]=y;
		return ;
	}
}b;
void log(){
	for(int i=1;i<=n;i++){
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	}
}
void add(int f,int t,int v){
	mst[++tot]=(Edge){f,t,v};
	nxt[tot]=head[f];
	head[f]=tot;
	return ;
}
void kru(){
	sort(a+1,a+m+1);
	b.init();
	for(int i=1;i<=m;i++){
		if(!b.check(a[i].f,a[i].t)){
			b.merge(a[i].f,a[i].t);
			add(a[i].f,a[i].t,a[i].v);
			add(a[i].t,a[i].f,a[i].v);
		}
	}
	return ;
}
void dfs(int x,int nfa){
	vis[x]=true;
	dep[x]=dep[nfa]+1;
	fa[x][0]=nfa;
	for(int i=1;(1<<i)<=dep[x];i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
		wmax[x][i]=min(wmax[x][i-1],wmax[fa[x][i-1]][i-1]);
	}
	for(int i=head[x];i;i=nxt[i]){
		int to=mst[i].t;
		if(to==nfa||vis[to]){
			continue;
		}
		wmax[to][0]=mst[i].v;
		dfs(to,x);
	}
	return ;
}
int lca(int x,int y){
	if(!b.check(x,y)){
		return -1;
	}
	int ans = INF;
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	while(dep[x]>dep[y]){
		ans=min(ans,wmax[x][lg[dep[x]-dep[y]]-1]);
		x=fa[x][lg[dep[x]-dep[y]]-1];
	}
	if(x==y){
		return ans;
	}
	for(int k=lg[dep[x]]-1;k>=0;k--){
		if(fa[x][k]!=fa[y][k]){
			ans=min(ans, min(wmax[x][k], wmax[y][k]));
			x=fa[x][k];
			y=fa[y][k];
		}
	}
	ans=min(ans,min(wmax[x][0],wmax[y][0]));
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	log();
	int x,y,z;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].f,&a[i].t,&a[i].v);
	}
	kru();
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,0);
			fa[i][0]=i;
			wmax[i][0]=INF;
		}
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}
