#include<stdio.h>
#include<string.h>

const int o=97;

char ans[10001][25],a[10001][25],dic[30][10001][25];
int num[30];

void insert(char* str){
	char chr=str[0];
	int i;
	
	chr-=o;
	
	for(i=0;i<num[chr];i++){
		if(!strcmp(str,dic[chr][i]))
			return;
	}
	
	strcpy(dic[chr][num[chr]++],str);
	
	return;
}

int find(char* str){
	char chr=str[0],s[30];
	int i,sum=0,l=strlen(str);
	
	memset(s,0,sizeof(s));
	chr-=o;
	
	for(i=0;i<num[chr];i++){
		strncpy(s,dic[chr][i],l);
		if(!strcmp(str,s)){
			strcpy(ans[++sum],dic[chr][i]);
		}
		if(sum==8)
			break;
	}
	
	return sum;
}

void quicksort(int l,int r){
	char mid[25],tmp[25];
	int tl=l,tr=r;
	
	memset(mid,0,sizeof(mid));
	strcpy(mid,a[(l+r)/2]);
	memset(tmp,0,sizeof(tmp));
	
	
	while(tl<=tr){
		while(strcmp(a[tl],mid)<0)
			tl++;
		while(strcmp(a[tr],mid)>0)
			tr--;
		if(tl<=tr){
			strcpy(tmp,a[tl]);
			strcpy(a[tl],a[tr]);
			strcpy(a[tr],tmp);
			tl++;tr--;
		}
	}
	if(tl<r)
		quicksort(tl,r);
	if(tr>l)
		quicksort(l,tr);
	return;
}
int main(){
	char str[255];
	int i,n,m,j,f;
	
	for(i=0;i<=10001;i++){
		memset(ans[i],0,sizeof(26));
		memset(a[i],0,sizeof(26));
	}
	for(i=0;i<31;i++)
		for(j=0;j<10002;j++)
		memset(dic[i],0,sizeof(26));
	memset(str,0,sizeof(str));
	memset(num,0,sizeof(num));
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",a[i]);
quicksort(0,n-1);
	
	for(i=0;i<n;i++)
		insert(a[i]);
	scanf("%d",&m);
	
	for(i=0;i<m;i++){
		scanf("%s",str);
		f=find(str);
		if(!f)
			printf("%s\n",str);
		else{
			for(j=1;j<f;j++)
				printf("%s ",ans[j]);
			printf("%s\n",ans[j]);
		}
	}
	
	return 0;
}
