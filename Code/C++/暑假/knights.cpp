#include<cstdio>
#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>

using namespace std;

const int inf=INT_MAX;
int sk,si,n,m,ans,minx;
int knight[1001][2]={0},invader[1001][2]={0},entrance[2]={0};

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			int x;
			scanf("%d",&x);
			if(!x)
				continue;
			if(x==1){
				knight[++sk][0]=i;
				knight[sk][1]=j;
			}
			if(x==2){
				invader[++si][0]=i;
				invader[si][1]=j;
			}
			
			if(x==3){
				entrance[0]=i;
				entrance[1]=j;
			}
		}
	minx=inf;
	for(int i=1;i<=sk;i++){
		int s=abs(entrance[0]-knight[i][0])+abs(entrance[1]-knight[i][1]);
		if(s<minx)
			minx=s;
	}
	ans=0;
	for(int i=1;i<=si;i++){
		int s=abs(entrance[0]-invader[i][0])+abs(entrance[1]-invader[i][1]);
		if(s<minx)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
