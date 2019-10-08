#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector <int> dic;
int a[1005];
int n,m;
int ans=0;
void query(int x){
	if(find(dic.begin(),dic.end(),x)==dic.end()){
		dic.push_back(x);
		ans++;
	}
	if(dic.size()>m){
		dic.erase(dic.begin());
	}
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		query(a[i]);
	}
	printf("%d",ans);
	return 0;
}
