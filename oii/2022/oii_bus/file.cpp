#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
constexpr int inf = 1e9;
const string quack = "quack";

queue<int> q;
vector<vector<pi>> adj;
vi d;

int pianifica(int n, int l, vector<vi> g) {
  d.resize(n, inf), d[0] = 0;
  adj.resize(n);

  for (int i = 0; i < l; i++)
    for (int j = 0; j < g[i].size(); j++)
      adj[g[i][j]].push_back({ i, j });

  q.push(0);
  while (not q.empty()) {
    int a = q.front(); q.pop();
    for (auto [line_b, pos_b]: adj[a]) {
      for (int j = pos_b + 1; j < g[line_b].size(); j++) {
        if (d[g[line_b][j]] > d[a] + 1) {
          d[g[line_b][j]] = d[a] + 1;
          q.push(g[line_b][j]);
        }
        else if (d[g[line_b][j]] < d[a] + 1) break;
      }
    } 
  }
  return d[n-1] == inf ? -1 : d[n-1] - 1;
}