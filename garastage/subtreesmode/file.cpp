#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
constexpr int maxn = 1 << 20;

int timer = 0;
vector<int> ts, res;

struct node {
  int i, tin, tout, val, parent, size = 1;
  bool heavy = false;
  vector<int> adj;
};
node nodes[maxn];

struct magic_vector {
  bool visited[maxn];
  vector<int> to_reset;
  int freq[maxn];
  int element = 0, max_freq = 0;
  void add(int val) {
    if (not visited[val])
      to_reset.push_back(val), visited[val] = 1;
    freq[val]++;
    if (freq[val] > max_freq) {
      max_freq = freq[val];
      element = val;
    }
    else if (freq[val] == max_freq) {
      element = min(element, val);
    }
  }
  void reset() {
    for (auto val: to_reset)
      visited[val] = freq[val] = 0;
    element = max_freq = 0;
    to_reset.clear();
  }
};

magic_vector v;

void dfs(int i) {
  ts.push_back(i);
  nodes[i].tin = timer++;
  int heaviest;

  if (not nodes[i].adj.empty())
    heaviest = nodes[i].adj[0];

  for (auto u: nodes[i].adj) {
    dfs(u);
    nodes[i].size += nodes[u].size;
    if (nodes[u].size > nodes[heaviest].size)
      heaviest = u;
  }

  if (not nodes[i].adj.empty())
    nodes[heaviest].heavy = true;

  nodes[i].tout = timer;
}

void trace(int i) {
  v.reset();
  int prv, l = nodes[i].tin, r = nodes[i].tin + 1;

  do {
    while (l >= nodes[i].tin) {
      v.add(nodes[ts[l--]].val);
    }
    while (r <= nodes[i].tout-1) {
      v.add(nodes[ts[r++]].val);
    }

    res[nodes[i].i] = v.element;
    prv = i;
    i = nodes[i].parent;

  } while (nodes[prv].heavy);
}

vector<int> solve(int n, vector<int> p, vector<int> a) {
  res.resize(n);
  ts.reserve(n);

  for (int i = 1; i < n; i++)
    nodes[p[i]].adj.push_back(i),
    nodes[i].parent = p[i];

  for (int i = 0; i < n; i++)
    nodes[i].val = a[i],
    nodes[i].i = i;

  dfs(0);

  for (int i = 0; i < n; i++)
    if (nodes[i].adj.empty())
      trace(i);

  return res;
}
