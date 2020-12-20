#include<stdio.h>
int main(){
	int s=0,n,h,j,i,f[10001],ans[10001];
	scanf("%d",&n);
	for(j=0;j<10001;j++){
			ans[j]=0;
		}
	for(i=0;i<n;i++){
		for(j=0;j<10001;j++){
			f[j]=0;
		}
		f[0]=1;
		scanf("%d",&h);
		s=0;
		while(h!=-1){
			s+=h;
			for(j=s;j>=h;j--){
				if(f[j-h])
				f[j]=1;
			}
			scanf("%d",&h);
		}
		for(j=0;j<=s;j++){
			if(f[j])
			ans[j]++;
		}
	}
	for(i=10000;i>-1;i--){
		if (ans[i]==n){
		    printf("%d\n",i);
		    return 0;
		}
	}
	printf("0\n");
	return 0;
}
