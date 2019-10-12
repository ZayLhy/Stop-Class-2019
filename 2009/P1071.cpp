#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
char ma[512];
bool vis[512];
bool visa[512];
using namespace std;
string A;
string ori,key;
int main(){
	cin>>key;
	cin>>ori;
	for(int i=0;i<key.length();i++){
		if((vis[key[i]]&&ma[key[i]]!=ori[i])||(visa[ori[i]]&&ma[key[i]]!=ori[i])){
			printf("Failed");
			return 0;
		}
		vis[key[i]]=visa[ori[i]]=true;
		ma[key[i]]=ori[i];
	}
	for(int i=0;i<26;i++){
		if(!vis[i+'A']){
			printf("Failed");
			return 0;
		}
	}
	cin>>A;
	for(int i=0;i<A.length();i++){
		printf("%c",ma[A[i]]);
	}
	return 0;
}
