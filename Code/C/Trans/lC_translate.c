#include<stdio.h>
FILE *p,*q;
char chr;
int j=0,brr[255];

void binary(char fig){
	int i=0,k=fig;
	if (fig==92)
	fprintf(q,"%c",fig);
	else{
		for(i=0;i<8;i++){
			brr[i]=k % 2;
			k/=2;
		}
	}
}
int main(){
	p=fopen("D:/running zone/words.txt","rt");
	q=fopen("D:/running zone/printedition.txt","wt");
	

	/*fprintf(q,"%s","Please input the words u wanna translate.\n");
	fprintf(q,"%s","[U should type an \"@\" when u finish]");*/
	
            chr=fgetc(p);
			while(chr!='@'){
			if (chr==32){
				fprintf(q,"%c",'\\');
				chr=fgetc(p);
				continue;
			}
			if (chr=='\n'){
				fprintf(q,"%c",'\n');
				chr=fgetc(p);
				continue;
			}
			if (((chr<=63)&&(chr>=33))||((chr<=126)&&(chr>=65))){
				binary(chr);
				for(j=7;j>=0;j--)
		        fprintf(q,"%d",brr[j]);
				fprintf(q,"%c",'%');
			}else{
				fprintf(q,"%c",chr);
				fprintf(q,"%c",'%');
			}
			chr=fgetc(p);
		}
		
		fprintf(q,"%s","\n@");
}
