#include<stdio.h>
#include<string.h>
struct rates{
	int source,destination;      //source是你手中的货币，destination是你想要的货币
	double rate;                 //汇率，我开了双精度，其实real应该可以
};
struct rates edge[10000];
int n,m;
void init(){
	int i,j;
	char currency[30][127],str1[127],str2[127];//字符串数组currency[i]记录货币名称，str1，str2
	for(i=1;i<=n;i++)
		scanf("%s",currency[i]);           //从1 到n读取货币名称
	scanf("%d",&m);                            //读取m（总共有m条边）
	for(i=1;i<=m;i++){                      //读取m条边的信息
		scanf("%s%lf%s",str1,&edge[i].rate,str2);        //读入两个货币名称与汇率
		for(j=1;j<=n&&(strcmp(str1,currency[j])!=0);j++);//从字符串数组中挨个比对，若符合，则赋值
		edge[i].source=j;
		for(j=1;j<=n&&(strcmp(str2,currency[j])!=0);j++);//同上
		edge[i].destination=j;
	}
	return;
}
int bf(){//bellman-ford 算法
	int i,j,k,u,v;
	double w,dist[31];
	memset(dist,0,sizeof(dist));//相当于fillchar（dist,sizeof(a),0），全部赋值为0，因为你要求最大值
	dist[1]=1;                  //你一开始有1单位货币
	for(i=1;i<n;i++){            //循环n-1次
		k=1;                     //k：=true
		for(j=1;j<=m;j++){
			u=edge[j].source;v=edge[j].destination;w=edge[j].rate;//赋个值，代码可以简洁点
			if( dist[u] * w > dist[v] ){//松弛操作
				dist[v]=dist[u]*w;
				k=0;          //k:=false ，判断是否松弛完成，省时间
			}
		}
		if(k)            //如果松弛完毕，break
			break;
	}
	for(i=1;i<=m;i++){//再次寻找是否还有能松弛的边
		u=edge[i].source;v=edge[i].destination;w=edge[i].rate;
		if(dist[u]*w>dist[v])
			return 1;     //若有回路，返回true
	}
	return 0;
}
int main(){
	int cas=0;   //计数，第几组数据
	while(1){     //俗称死循环，相当于 → while(true)
		cas++;                           // inc(cas)
		scanf("%d",&n);                  // readln(n);
		if(!n)                           //if n=0 then break;
			break;
		init();
		printf("Case %d: ",cas);         //write('Case ',cas,':');
		if(bf())                         //if bf=true then writeln('Yes') 
 			printf("Yes\n");             //else writeln('No');
		else
			printf("No\n");              //readln;（PASCAL玩家注意，每组数据都有一行隔开）
	}
	return 0;
}
