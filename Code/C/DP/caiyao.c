#include<stdio.h>

int t,m,i,c,f[10000],time[10000],v[10000];

void readin(){
	scanf("%d%d",&t,&m);
	for(i=0;i<100;i++){
		time[i]=0;
		v[i]=0;
		f[i]=0;
	}
	for(i=1;i<=m;i++)
	scanf("%d%d",&time[i],&v[i]);
	return;
}
int main(){
	readin();
	for(i=1;i<=t;i++){
		for(c=t;c>=0;c--){
			if((c>=time[i])&&((f[c-time[i]]+v[i])>f[c]))
			f[c]=f[c-time[i]]+v[i];
		}
	}
	printf("%d\n",f[t]);
	return 0;
}
