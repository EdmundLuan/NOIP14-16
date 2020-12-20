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
	char str[999];
	int j=0,word=0,i=0,ls=0,h=7;
	
	p=fopen("printedition.txt","rt");
	q=fopen("t_b_words.txt","wt");
	fscanf(p,"%s",str);
	ls=strlen(str);
	while (str[ls-1]!='@'){	
		for (i=0;i<ls;i++){
			if ((str[i]=='%')||(str[i]=='\\')){
				if (str[i]=='%')
				continue;
				fprintf(q,"%c",' ');
			}else{
				if (h==7)
				word=0;
				word+=(str[i]-48)*cifang(2,h);
				h--;
			}		
			if (h<0){
				fprintf(q,"%c",word);
				h=7;
			}
		}
		fprintf(q,"\n");
		fscanf(p,"%s",str);
		ls=strlen(str);
	}
}
