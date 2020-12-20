#include<stdio.h>
#include<limits.h>
int n,w[200][200],sum;
void prim(int v){
	int i,j,k,mi=INT_MAX,dist[200]={INT_MAX},flag[200]={0};
	for(i=1;i<=n;i++)
		dist[i]=w[v][i];
	flag[v]=1;
	sum=0;
	for(i=1;i<n;i++){
		mi=INT_MAX;
		for(j=1;j<=n;j++){
			if((dist[j]<mi)&&(flag[j]==0)){
				k=j;
				mi=dist[j];
			}
		}
		flag[k]=1;
		sum+=dist[k];
		for(j=1;j<=n;j++){
			if(w[j][k]<dist[j])
				dist[j]=w[j][k];
		}
	}
	return;
}
int main(){
	int i,j,l,m,k,s=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
	        w[i][j]=INT_MAX;
	for(i=1;i<=k;i++){
		scanf("%d%d%d",&j,&l,&m);
		w[j][l]=w[l][j]=m;
		s+=m;
	}
	prim(1);
	printf("%d\n",s-sum);
	return 0;
}
