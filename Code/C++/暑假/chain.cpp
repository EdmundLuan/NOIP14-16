#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int n,ans=0;
int f[100001],a[101],p[101];
bool flag[101]={0};

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		//int x;
		scanf("%d",&p[i]);
	}
	fill(f,f+n,1);
	fill(a+1,a+101,1);
	for(int i=0;i<n;i++){
		
		for(int j=1;j<=100;j++){
			if(!flag[j])
				continue;
			if(!((i+1)%j)){
				if(f[i]<a[j]+1){
					
					f[i]=a[j]+1;
				}
				//break;
			}	
		}
		a[p[i]]=max(a[p[i]],f[i]);
		flag[p[i]]=true;
	}
	for(int i=0;i<n;i++){
		if(ans<f[i])
			ans=f[i];
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
