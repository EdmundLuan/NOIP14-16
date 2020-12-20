#include<stdio.h>
int w[30],c[30],p[30],f[201];
void origin(int a,int b){
    int i=0;
	for(;i<=a;i++){
	c[i]=0;
	w[i]=0;
	p[i]=0;
	}
	for(i=0;i<=b;i++)
	f[i]=0;
	return;
}
int max(int a,int b){
    if(a>=b)
	return a;
	else
	return b;
	}
int main(){
	int v,n,i,j,k;
	scanf("%d%d",&v,&n);
	origin(n,v);
	for(i=1;i<=n;i++)
	scanf("%d%d%d",&w[i],&c[i],&p[i]);
	for(i=1;i<=n;i++){
		if(p[i]==0){
			for(j=w[i];j<=v;j++)
			f[j]=max(f[j],f[j-w[i]]+c[i]);
		}
		else{
			for(j=v;j>=0;j--){
				for(k=0;k<=p[i];k++){
					if(j<k*w[i])
					break;
					f[j]=max(f[j],f[j-k*w[i]]+k*c[i]);
				}
			}
		}
	}
	printf("%d\n",f[v]);
	return 0;
}
