#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define maxn(a,b) ((a)>(b)?(a):(b))

typedef struct _node_{
	long long state;
	long long ans;
	struct _node_* next;
}node;

node* arr[1000017];

long long hash(long long key){
	return(key%1000007);
}

long long search(long long n){
	node* tmp;
	long long a,b;
	
	if(!n)
		return 0;
	tmp=arr[hash(n)];
	while(tmp!=NULL){
		if(n==tmp->state)
			return tmp->ans;
		tmp=tmp->next;
	}
	a=(long long)maxn(n,search(n/2)+search(n/3)+search(n/4));
	tmp=(node*)malloc(sizeof(node*));
	if((node*)malloc(sizeof(node*))==NULL)
	    printf("Caonima!");
	tmp->state=n;
	tmp->ans=(long long)a;
	tmp->next=(node*)arr[hash(n)];
	arr[hash(n)]=tmp;
	return a;
}

int main(){
	long long t,n,i,k,an=0;
	for(i=0;i<=100007;i++)
		arr[i]=NULL;
	scanf("%I64d",&t);
	for(k=0;k<t;k++){
		scanf("%I64d",&n);
		an=search(n);
		printf("%I64d\n",an);
	}
	system("pause");
	return 0;
}
