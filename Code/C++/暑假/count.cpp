#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n,ans=0;
int father[10]={0},map[10][10]={0};
bool flag[10]={0};

bool find(int x,int y){
	if(father[x]==-1)
		return true;
	while(father[x]!=x){
		x=father[x];
		if(x==y)
			return false;
	}
		
	return true;
}

int findset(int x){
	while(father[x]!=x)
		x=father[x];
	return x;
}

void unionn(int u,int v){
	int fu=findset(u),fv=findset(v);
	if(fu!=fv)
		father[u]=father[v];
}

bool check(){
	for(int i=0;i<n;i++){
		if(!flag[i])
			return false;
	}
	return true;
}

void search(int target){
	//int tmp=father[target];
	if(flag[target])
		return;
	for(int i=0;i<n;i++){
		if(!map[i][target])
			continue;
		if(!find(i,target))
			continue;
		father[target]=i;
		flag[target]=true;
	}
	
}

int main(){
	char chr=0;
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n;chr=getchar();
	//fill(*map,*map+100,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			chr=getchar();
			map[i][j]=chr-48;
		}
		chr=getchar();	
	}
	/*
for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d",map[i][j]);
		printf("%c",'\n');
	}*/	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			father[j]=-1;
		father[i]=i;flag[i]=true;
		for(int k=0;k<n;k++){
			search(k);
		}
		if(check())
			ans++;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
