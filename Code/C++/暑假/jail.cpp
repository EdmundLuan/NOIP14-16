#include<iostream>
#include<cstdio>
#include<climits>
#include<string>

using namespace std;
int n,d;
int a[1000005][6],maxc[32],minc[32];//"maxc" =the max sum of the combination, "minc" =the min sum of the combination

int solve(){
	int tmp=1<<d;//calculate how many combinations
	for(int i=0;i<tmp;i++){//origin()
		maxc[i]=-INT_MAX;
		minc[i]=INT_MAX;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<tmp;j++){
			int sum=0,b=j;//"b" =the bits u still need to use
			for(int k=0;k<d;k++){
				if(b&1)
					sum+=a[i][k];//to confirm whether the last bit is "0" or "1"
				else
					sum-=a[i][k];
				b>>=1;
			}
			if(maxc[j]<sum)
				maxc[j]=sum;
			if(minc[j]>sum)
				minc[j]=sum;
		}
	int ans=-INT_MAX;
	for(int i=0;i<tmp;i++){
		if(maxc[i]-minc[i]>ans)
			ans=maxc[i]-minc[i];
	}
	return ans;
}

int main(){
	cin>>n>>d;
	for(int i=0;i<n;i++)
		for(int j=0;j<d;j++)
			scanf("%d",&a[i][j]);
	cout<<solve()<<endl;
	return 0;
}
