#include<stdio.h>
#include<string.h>
struct rates{
	int source,destination;      //source�������еĻ��ң�destination������Ҫ�Ļ���
	double rate;                 //���ʣ��ҿ���˫���ȣ���ʵrealӦ�ÿ���
};
struct rates edge[10000];
int n,m;
void init(){
	int i,j;
	char currency[30][127],str1[127],str2[127];//�ַ�������currency[i]��¼�������ƣ�str1��str2
	for(i=1;i<=n;i++)
		scanf("%s",currency[i]);           //��1 ��n��ȡ��������
	scanf("%d",&m);                            //��ȡm���ܹ���m���ߣ�
	for(i=1;i<=m;i++){                      //��ȡm���ߵ���Ϣ
		scanf("%s%lf%s",str1,&edge[i].rate,str2);        //���������������������
		for(j=1;j<=n&&(strcmp(str1,currency[j])!=0);j++);//���ַ��������а����ȶԣ������ϣ���ֵ
		edge[i].source=j;
		for(j=1;j<=n&&(strcmp(str2,currency[j])!=0);j++);//ͬ��
		edge[i].destination=j;
	}
	return;
}
int bf(){//bellman-ford �㷨
	int i,j,k,u,v;
	double w,dist[31];
	memset(dist,0,sizeof(dist));//�൱��fillchar��dist,sizeof(a),0����ȫ����ֵΪ0����Ϊ��Ҫ�����ֵ
	dist[1]=1;                  //��һ��ʼ��1��λ����
	for(i=1;i<n;i++){            //ѭ��n-1��
		k=1;                     //k��=true
		for(j=1;j<=m;j++){
			u=edge[j].source;v=edge[j].destination;w=edge[j].rate;//����ֵ��������Լ���
			if( dist[u] * w > dist[v] ){//�ɳڲ���
				dist[v]=dist[u]*w;
				k=0;          //k:=false ���ж��Ƿ��ɳ���ɣ�ʡʱ��
			}
		}
		if(k)            //����ɳ���ϣ�break
			break;
	}
	for(i=1;i<=m;i++){//�ٴ�Ѱ���Ƿ������ɳڵı�
		u=edge[i].source;v=edge[i].destination;w=edge[i].rate;
		if(dist[u]*w>dist[v])
			return 1;     //���л�·������true
	}
	return 0;
}
int main(){
	int cas=0;   //�������ڼ�������
	while(1){     //�׳���ѭ�����൱�� �� while(true)
		cas++;                           // inc(cas)
		scanf("%d",&n);                  // readln(n);
		if(!n)                           //if n=0 then break;
			break;
		init();
		printf("Case %d: ",cas);         //write('Case ',cas,':');
		if(bf())                         //if bf=true then writeln('Yes') 
 			printf("Yes\n");             //else writeln('No');
		else
			printf("No\n");              //readln;��PASCAL���ע�⣬ÿ�����ݶ���һ�и�����
	}
	return 0;
}
