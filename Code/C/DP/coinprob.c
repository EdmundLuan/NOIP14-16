#include<stdio.h>
int main(){
    int i,j,max[50000],min[50000],n,s,a[1000];
	scanf("%d",&n);
	scanf("%d",&s);
	/*if (s==0){
	    printf('0');
		return 0;
	}*/
	for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(i=1;i<=s;i++){
	    max[i]=-2000000;
		min[i]=2000000;
    }
	min[0]=max[0]=0;
	for(i=1;i<=n;i++){
	    for(j=a[i];j<=s;j++){
		    if ((max[j-a[i]]+1)>max[j])
			max[j]=max[j-a[i]]+1;
			if ((min[j-a[i]]+1)<min[j])
			min[j]=min[j-a[i]]+1;
		}
	}
	printf("%d\n%d",min[s],max[s]);
	return 0;
}
