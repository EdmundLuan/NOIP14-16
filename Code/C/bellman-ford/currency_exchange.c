#include<stdio.h>
#include<string.h>
struct rates{
	int source,destination;
	float rate,commission;
};
struct rates edge[10001];
int n,m,have;
double balance;
int bf(){
	int i,j,k,u,v;
	double t,w,dist[101];
	memset(dist,0,sizeof(dist));
	dist[have]=balance;
	for(i=1;i<n;i++){
		k=1;
		for(j=1;j<=m;j++){
			u=edge[j].source;v=edge[j].destination;w=edge[j].rate;t=edge[j].commission;
			if((dist[u]-t)*w>dist[v]){
				dist[v]=(dist[u]-t)*w;
				k=0;
			}
		}
		if(k)
		    break;
	}
	for(i=1;i<=m;i++){
		u=edge[i].source;v=edge[i].destination;w=edge[i].rate;t=edge[i].commission;
		if((dist[u]-t)*w>dist[v])
			return 1;
	}
	return 0;
}
int main(){
	int i,k=0,x,y;
	scanf("%d%d%d%lf",&n,&m,&have,&balance);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		edge[++k].source=x;
		edge[k].destination=y;
		scanf("%f%f",&edge[k].rate,&edge[k].commission);
		edge[++k].source=y;
		edge[k].destination=x;
		scanf("%f%f",&edge[k].rate,&edge[k].commission);
	}
	m=k;
	if(bf())
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
