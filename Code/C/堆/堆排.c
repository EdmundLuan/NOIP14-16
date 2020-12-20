#include<stdio.h>
int i,n,tot,d[100]={0};
void down(int a){
	int b=a,tmp,j;
	while(b<=tot/2){
		j=2*b;
		if((j+1<=tot)&&(d[j]>d[j+1]))
			j++;
		if(d[b]>d[j]){
			tmp=d[b];
			d[b]=d[j];
			d[j]=tmp;
			b=j;
		}
		else
			break;
	}
}
int main(){
	int t=0;
	printf("How many numbers u wanna put in?\n");
	scanf("%d",&n);
	printf("Put in the numbers now.\n");
	for(i=1;i<=n;i++)
		scanf("%d",&d[i]);
	tot=n;
	for(i=tot/2;i>0;i--)
		down(i);
	for(i=1;i<=n;i++){
		t=d[1];
		d[1]=d[tot];
		d[tot]=t;
		tot--;
		down(1);
	}
	for(i=n;i>0;i--)
		printf("%d%c",d[i],' ');
	printf("\n");
	return 0;
}
