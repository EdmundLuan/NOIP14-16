#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<climits>

using namespace std;

int who,n,m,first,maxn,points;
int sum[1005]={0},statistics[7]={0};

int main(){
	cin>>n>>m;
	first=1;maxn=-INT_MAX;
	for(int i=0;i<m;i++){
		who=first;
		for(int j=0;j<n;j++){
			memset(statistics,0,sizeof(statistics));
			for(int k=0,x=0;k<6;k++){
				scanf("%d",&x);
				statistics[x]++;
			}
			points=0;
			for(int k=1,maxx=0;k<7;k++){
				if(maxx<statistics[k]){
					maxx=statistics[k];
					points=k;
				}
			}
			if(points==1||points==4)
				sum[who]+=statistics[points]*2;
			else
				sum[who]+=statistics[points];
			if(sum[who]>maxn){
				maxn=sum[who];
				first=who;
			}
			who++;
			if(who>n)
				who=1;
		}
	}
	printf("%d %d\n",first,sum[first]);
	return 0;
}
