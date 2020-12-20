#include<stdio.h>

int main(){
	int a,b,c,f,i;
	//freopen("nim.in","r",stdin);
	//freopen("nim.out","w",stdout);
	//for(i=0;i<9;i++){
		scanf("%d%d%d",&a,&b,&c);
		f=a^b^c;
		if(!f)
			printf("win\n");
		else
			printf("lose\n");
	//}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
