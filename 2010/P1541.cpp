#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 50 + 5;
int f[N][N][N][N];
int buk[5];
int n,m;
int ai[360];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&ai[i]);
	}
	f[0][0][0][0]=ai[1];
	int ca;
	for(int i=1;i<=m;i++){
		scanf("%d",&ca);
		buk[ca]++;
	}
	int offset=1;
	for(int a=0;a<=buk[1];a++){
		for(int b=0;b<=buk[2];b++){
			for(int c=0;c<=buk[3];c++){
				for(int d=0;d<=buk[4];d++){
					offset+=a+2*b+3*c+4*d;
					if(a) f[a][b][c][d]=max(f[a][b][c][d],f[a-1][b][c][d]+ai[offset]);
					if(b) f[a][b][c][d]=max(f[a][b][c][d],f[a][b-1][c][d]+ai[offset]);
					if(c) f[a][b][c][d]=max(f[a][b][c][d],f[a][b][c-1][d]+ai[offset]);
					if(d) f[a][b][c][d]=max(f[a][b][c][d],f[a][b][c][d-1]+ai[offset]);
					offset=1;
				}
			}
		}
	}
	printf("%d",f[buk[1]][buk[2]][buk[3]][buk[4]]);
	return 0;
}
