#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 110;
bool g[maxn][maxn];
int match[maxn];
bool vis[maxn];
int n;
bool dfs(int cur) {
  for (int i = 1; i <= n; i++) {
    if (g[cur][i] == true && !vis[i]) {
      vis[i] = true;
      int t = match[i];
      if (t == -1 || dfs(t)) {
        match[i] = cur;
        return true;
      }
    }
  }
  return false;
}
int hungary() {
  int res = 0;
  for (int i = 1; i <= n; i++)  match[i] = -1;

  for (int i = 1; i <= n; i++) {
    memset(vis, false, sizeof(vis));
    if (dfs(i))  res++;
  }
  return res;
}
