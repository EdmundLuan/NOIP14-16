#include<stdio.h>
#include<string.h>
#include<limits.h>
int n,dist[2001],rp[2001][2001];
int minx(int a,int b){
	if(a<=b)
	    return(a);
    else
        return(b);
}
void origin(){
	int i;
	for(i=1;i<=n;i++)
			dist[i]=rp[1][i];
	return;
}
void dijkstra(int vi){
	int k,i,vj,pos,maxn;
	short searched[2001];
	origin();
	memset(searched,0,sizeof(searched));
	searched[vi]=1;
	for(i=1;i<n;i++){
		maxn=0;
		for(vj=1;vj<=n;vj++){
			if(maxn<dist[vj]&&searched[vj]==0){
				maxn=dist[vj];
				pos=vj;
			}
		}
		searched[pos]=1;
		for(vj=1;vj<=n;vj++){
			if(searched[vj]==1||rp[pos][vj]<=0)
				continue;
			k=minx(dist[pos],rp[pos][vj]);
			if(k>dist[vj])
				dist[vj]=k;
		}
	}
	for(i=2;i<=n;i++)
		printf("%d\n",dist[i]);
	return;
}
int main(){
	int v,u,r;
	scanf("%d",&n);
	for(v=1;v<=n;v++)
	    for(u=1;u<=n;u++)
	        rp[v][u]=0;
	while(1){
		scanf("%d%d%d",&v,&u,&r);
		if(v==0&&u==0&&r==0)
			break;
		rp[v][u]=r;
	}
	dijkstra(1);
	return 0;
}
