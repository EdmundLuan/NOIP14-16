#include<iostream>

using namespace std;

int f[1000000]={0};

int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	int n=0;
	cin>>n;
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=n;i++)
		f[i]=(f[i-1]+f[i-2]%15746)%15746;
	cout<<f[n]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0000
1100
0011
1111
1001
*/
