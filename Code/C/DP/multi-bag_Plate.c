#include<stdio.h>
int v[6001],w[6001],s[6001],f[6001];
void origin(int a){
    int i=0;
	for(;i<=a;i++){
	v[i]=0;
	w[i]=0;
	s[i]=0;
	f[i]=0;
	}
	return;
}
int max(int a,int b){
    if(a>=b)
	return a;
	else
	return b;
	}
int main(){
    int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	origin(m);
	for(i=1;i<=n;i++)
	scanf("%d%d%d",&v[i],&w[i],&s[i]);
	for(i=1;i<=n;i++){
	    for(j=m;j>=0;j--){
		    for(k=1;k<=s[i];k++){
			    if(j<k*v[i])
				break;
				f[j]=max(f[j],f[j-k*v[i]]+k*w[i]);
			}
		}
	}
	printf("%d\n",f[m]);
	return 0;
}
