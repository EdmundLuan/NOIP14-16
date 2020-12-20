#include<stdio.h>
#include<string.h>
int father[5001]={0},n;
char name[2500][15];
void origin(int n){
	int i;
	for(i=1;i<=n;i++){
		father[i]=i;
    }
	return;
}
int getnum(char*n1){
	int i;
	for(i=1;i<=n;i++){
		if(strcmp(n1,name[i])==0){
			//printf("%s %d\n",n1,i);
			return(i);
		}

	}
	return 0;
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
	int i,m,p;
	char m1[15],m2[15];
	scanf("%d%d%d",&n,&m,&p);
	origin(n);
	for(i=1;i<=n;i++)
		scanf("%s",name[i]);
	for(i=1;i<=m;i++){
		scanf("%s%s",m1,m2);
		unionn(getnum(m1),getnum(m2));
	}
	for(i=1;i<=p;i++){
		scanf("%s%s",m1,m2);
		if(getfather(getnum(m1))!=getfather(getnum(m2)))
			printf("cc cry\n");
		else
			printf("safe\n");
	}
	return 0;
}
