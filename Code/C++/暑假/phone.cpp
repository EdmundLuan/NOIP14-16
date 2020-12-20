#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<climits>


using namespace std;

struct EDGE {
	int v, w, next;
} edge[20010];

queue<int>q;
int n, p, k, index = 1, ans = 0, l = 0, r = 10000000;
int pre[2010];
bool vis[2010];
int dist[2010];
//bool flag;


void spfa1() {
	while (!q.empty())
		q.pop();
	memset(vis, 0, sizeof(vis));
	fill(dist, dist + 2010, INT_MAX); dist[1] = 0;
	q.push(1);
	vis[1] = true;
	while (!q.empty()) {
		int top = q.front();
		int w1 = dist[top];
		q.pop();
		vis[top] = false;
		for (int i = pre[top]; i != -1; i = edge[i].next) {
			int e = edge[i].v;
			int w2 = edge[i].w;
			if (dist[e] > w1 + w2) {
				dist[e] = w1 + w2;
				if (!vis[e]) {
					vis[e] = true;
					q.push(e);
				}
			}
		}
	}
}

bool spfa2(int x) {
	int sum = 0;
	while (!q.empty())
		q.pop();
	memset(vis, 0, sizeof(vis));
	fill(dist, dist + 2010, INT_MAX);
	q.push(1);
	vis[1] = true;
	while (!q.empty()) {
		int top = q.front();
		int w1 = dist[top];
		q.pop();
		vis[top] = false;
		for (int i = pre[top]; i != -1; i = edge[i].next) {
			int e = edge[i].v;
			//int w2=edge[i].w;
			if (edge[i].w > x)
				sum = w1 + 1;
			else
				sum = w1;
			if (dist[e] > sum) {
				dist[e] = sum;
				if (!vis[e]) {
					vis[e] = true;
					q.push(e);
				}
			}

		}
	}
	if (dist[n] >= k)
		return true;
	else
		return false;
}

void read(int &x) {
	char chr = getchar();
	x = 0;
	while (chr < '0' || chr > '9')
		chr = getchar();
	while (chr <= '9' && chr >= '0') {
		x *= 10; x += chr - 48;
		chr = getchar();
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	read(n); read(p);
	read(k);
	memset(pre, -1, sizeof(pre));
	for (int i = 0; i < p; i++) {

		int x, y, z;
		bool flag;

		read(x); read(y); read(z);
		// for(flag=false,j=pre[x];j!=-1;j=edge[j].next){
		// 	if(y==edge[j].v){
		// 		if(z<edge[j].w)
		// 			edge[j].w=z;
		// 		flag=true;
		// 		break;
		// 	}
		// }
		// if(flag)
		// 	continue;

		edge[index].v = y; edge[index].w = z;
		edge[index].next = pre[x];
		pre[x] = index++;
		swap(x, y);
		edge[index].v = y; edge[index].w = z;
		edge[index].next = pre[x];
		pre[x] = index++;
	}
	spfa1();
	if (dist[n] == INT_MAX) {
		cout << "-1" << endl;
		return 0;
	}
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (spfa2(mid)) {
			ans = mid;
			r = mid - 1;
		} else
			l = mid + 1;
	}
	cout << ans << endl;
	fclose(stdin);
	return 0;
}
