#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const string quack = "quack";

int n, last;
vi visited, s;

void dfs(int v) {
   visited[v] = 1;
   int u = s[v];
   if (visited[u] == 0) dfs(u);
   else if (visited[u] == 1) last = u;
   visited[v] = 2;
}

int main() {
   cin >> n;
   s.resize(n);
   visited.resize(n, 0);
   int res = 0;
   for (int i = 0; i < n; i++) cin >> s[i];
   for (int i = 0; i < n; i++) {
      if (not visited[i]) {
         last = -1;
         dfs(i);
         if (last == -1) continue;
         int count = 1;
         for (int x = s[last]; x != last; x = s[x]) {
            count++;
         }
         res = max(res, count);
      }
   }
   cout << res << endl;
}