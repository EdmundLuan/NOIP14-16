#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

struct DATA{
	int pos,speed;
}data[300001];

int n,ans;
int a[300001]={0},b[300001]={0};

bool cmp(DATA a,DATA b){
	return a.pos<b.pos;
}

void merge(int l,int r,int mid){
	int i=l,j=mid+1,k=l;
	while(k<=r){
		if((i<=mid)&&((j>r)||(a[i]<=a[j]))){
			b[k++]=a[i++];
		}
		else{
			b[k++]=a[j++];
			ans+=mid-i+1;
		}
	}
	for(int p=l;p<=r;p++)
		a[p]=b[p];
}

void mergesort(int l,int r){
	int mid;
	if(l!=r){
		mid=(l+r)>>1;
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l,r,mid);
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d%d",&data[i].pos,&data[i].speed);
	}
	sort(data,data+n,cmp);
	for(int i=0;i<n;i++)
		a[i]=data[i].speed;
	ans=0;
	mergesort(0,n-1);
	cout<<ans<<endl;
	return 0;
}
