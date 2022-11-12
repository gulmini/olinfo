#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
const string quack = "quack";

vi d, tin, tout;
vector<vi> adj, st, up;
int leaf, root = 0, timer = 0, res = 0;

inline bool anc(int u, int v) {
  return tin[u] <= tin[v] and tout[u] >= tout[v];
}

inline int lca(int u, int v) {
  if (anc(u, v)) return u;
  if (anc(v, u)) return v;

  for (int j = 18; j >= 0; j--)
    if (not anc(up[j][u], v))
      u = up[j][u];

  return up[0][u];
}

inline int dist(int u, int v) {
  return d[u] + d[v] - 2*d[lca(u, v)];
} 

void dfs(int i, int p) {
  tin[i] = timer++;
  up[0][i] = p;

  for (auto u: adj[i]) {
    if (u == p) continue;
    d[u] = d[i] + 1;
    dfs(u, i);
  }

  tout[i] = timer++;
}

int build(int n, vector<int> a, vector<int> b) {
  d.resize(n); tin.resize(n); tout.resize(n);
  adj.resize(n); up.resize(19, vi(n));

  for (int i = 0; i < n-1; i++) {
    adj[a[i]].push_back(b[i]);
    adj[b[i]].push_back(a[i]);
  }

  d[root] = 0;
  dfs(root, root);
  root = max_element(d.begin(), d.end()) - d.begin();

  d[root] = 0;
  dfs(root, root);
  leaf = max_element(d.begin(), d.end()) - d.begin();

  for (int j = 1; j < 19; j++)
    for (int i = 0; i < n; i++)
      up[j][i] = up[j-1][up[j-1][i]];

  for (int i = 0; i < n; i++) {
    if (i == root or i == leaf) continue;
    res = max(res, dist(i, root) + dist(i, leaf));
  }

  return res + dist(root, leaf);
}
