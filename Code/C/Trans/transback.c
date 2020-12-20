#include<stdio.h>
#include<string.h>
int cifang(int a,int b){
	int k=0,c=1;
	for (;k<b;k++)
	c=c*a;
	return c;
}
int main(){
	FILE *p,*q;
	char str[2550];
	int j=0,word=0,i=0,ls=0;
	
	p=fopen("result.txt","rt");
	q=fopen("trans_back.txt","wt");
	while (str[strlen(str)-1]!='@'){
		fscanf(p,"%s",str);
		ls=strlen(str);
		for (;i<ls;i++){
		if ((str[i]=='%')||(str[i]=='\\')){
			j++;
			if (str[i]=='%')
			continue;
			fprintf(q,"%c",' ');
		}else{
			int k=j+8;
			word=0;
			int h=7;
			for(;j<k;j++){
				
				word+=str[j]*cifang(2,h);
				h--;
			}
			fprintf(q,"%d%c",word,' ');
		}
	}
        fprintf(q,"\n");
	}
}
