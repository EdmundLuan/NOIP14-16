#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,x,ans,g[1010][1010];
bool f[1010][1010][10];

void read(int &x){
	char chr=getchar();
	x=0;
	while(chr<'0'||chr>'9')
		chr=getchar();
	x=chr-48;
}

int main(){
	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			read(g[i][j]);
			for(int k=1;k<=g[i][j];k++)
				f[i][j][k]=true;
		}
	ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=g[i][j];k++){
				if(!f[i-1][j][k])
					ans++;
				if(!f[i+1][j][k])
					ans++;
				if(!f[i][j-1][k])
					ans++;
				if(!f[i][j+1][k])
					ans++;
				if(!f[i][j][k+1])
					ans++;
				if(!f[i][j][k-1])
					ans++;
			}
	cout<<ans<<endl;
	fclose(stdin);
	return 0;
}
