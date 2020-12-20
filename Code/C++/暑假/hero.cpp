#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

struct DATA{
	int u,v,w;
}data[10000005];

/*
struct DATA{
	int u,v,w;
};
*/
bool comparison(DATA a,DATA b){
	return a.w<b.w;
}

int m=0,rest,n,k;
int father[1005];
//DATA data[10000005];


void read(int &x){
	char chr=getchar();
	x=0;
	while(chr<'0'||chr>'9')
		chr=getchar();
	while(chr>='0'&&chr<='9'){
		x*=10;
		x+=chr-48;
		chr=getchar();
	}
}

int find(int x){
	if(father[x]!=x){
		int root=find(father[x]);
		return father[x]=root;
	}
	else
		return x;
}

bool unionn(int a,int b){
	int fa=find(a),fb=find(b);
	if(fa!=fb){
		father[a]=fb;
		return true;
	}
	return false;	
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1,cache=0;j<=n;j++){
			read(cache);
			if(i==j||j<=i)
				continue;
			data[++m].u=i;data[m].v=j;
			data[m].w=cache;
		}

	for(int i=0;i<=n;i++)
		father[i]=i;
	sort(data+1,data+1+m,comparison);
	rest=m;
	int i;
	for(i=1;rest>=k;i++){
		if(unionn(data[i].u,data[i].v))
			rest--;
	}
	cout<<data[--i].w<<endl;
	return 0;
}
