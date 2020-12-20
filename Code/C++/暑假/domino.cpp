#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<windows.h>

using namespace std;

vector<int>f[10001];

int n;
//char s;

void pluss(vector<int> &a,vector<int> &b,vector<int> &c){
	int j=0,p=0;
	for(int i=1;i<=b.size();i++){
		p=a[i]+b[i];
		c.push_back(p%10+j);
		j=p/10;
	}
	if(j)
		c.push_back(j);
}

int main(){
	freopen("domino.in","r",stdin);
	freopen("domino.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		if(!f[i].empty())
			f[i].clear();
	}
	f[3].push_back(2);f[4].push_back(6);
	/*
for(int i=0;i<=4;i++){
		for(int j=1;j<=f[i].size();i++){
			int k=f[i].front();
			cout<<k;
		}
	}*/
	for(int i=5;i<=n;i++){
		pluss(f[i-2],f[i-1],f[i]);
		//plus(f[i],f[i-2]);
	}
	while(f[n].size()){
		printf("%d",f[n].back());
		f[n].pop_back();
	}
	cout<<endl;
	//system("pause");
	fclose(stdin);
	fclose(stdout);
	return 0;
}