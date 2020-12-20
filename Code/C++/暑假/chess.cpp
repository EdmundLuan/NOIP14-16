#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

void read(int &x){
	char chr=getchar();
	x=0;
	while(chr<'0'||chr>'9')
		chr=getchar();
	while(chr>='0'&&chr<='9'){
		x*=10;
		x+=chr-48;
		chr=getchar();
	}
}

int main(){
	int n,k,a[100010],b[100010],sum;
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(n);read(k);
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));
	for(int i=0;i<n;i++)
		read(a[i]);
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	sort(b,b+n-1);
	sum=0;
	for(int i=0;i<k;i++)
		sum+=b[i];
	printf("%d\n",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
