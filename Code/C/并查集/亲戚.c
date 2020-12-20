#include<stdio.h>
int father[5001]={0};
void origin(int n){
	int i;
	for(i=1;i<=n;i++)
		father[i]=i;
	return;
}
int getfather(int a){
	if(father[a]==a)
		return(a);
	else{
		father[a]=getfather(father[a]);
		return(father[a]);
	}
}
void unionn(int a,int b){
	int Fu,Fv;
	Fu=getfather(a);
	Fv=getfather(b);
	if(Fu!=Fv)
		father[Fu]=Fv;
	return;
}
int main(){
	int i,n,m,p,m1,m2;
	scanf("%d%d%d",&n,&m,&p);
	origin(n);
	for(i=1;i<=m;i++){
		scanf("%d%d",&m1,&m2);
		unionn(m1,m2);
	}
	for(i=1;i<=p;i++){
		scanf("%d%d",&m1,&m2);
		if(getfather(m1)!=getfather(m2))
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
