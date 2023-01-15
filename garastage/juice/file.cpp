#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<int> vint;

ll n, m, k, q;
vint ts;
vector<vint> adj;
vector<pair<int, ll>> fruits;

struct magic_map {
  map<int, ll> m;

  void parallel_merge(magic_map &o) {
    for (auto [t, val]: o.m) m[t] += val;
  }

  void vertical_merge(pair<int, ll> fruit) {
    auto [t, w] = fruit;
    m[t] += w;
    auto it = next(m.find(t));
    ll sum = 0;
    while (it != m.end() and sum + it->second <= w) {
      sum += it->second;
      it++;
      m.erase(prev(it));
    }
    if (it != m.end()) it->second -= w-sum;
  }
};

void dfs(int i) {
  ts.push_back(i);
  for (auto u: adj[i]) dfs(u);
}

stack<magic_map> memo;

ll harvest(int n, int m, int k, vint& p, vint& v, vint& d, vint& w) {
  adj.resize(n);
  fruits.resize(n);

  for (int i = 0; i < m; i++)
    fruits[v[i]] = { d[i], w[i] };

  for (int i = 1; i < n; i++)
    adj[p[i]].push_back(i);

  dfs(0);
  reverse(ts.begin(), ts.end());

  for (auto i: ts) {
    magic_map acc;

    stack<magic_map> children;

    for (int _ = 0; _ < adj[i].size(); _++) {
      if (acc.m.size() < memo.top().m.size())
        swap(acc, memo.top());
      children.push(memo.top());
      memo.pop();
    }

    for (int _ = 0; _ < adj[i].size(); _++) {
      acc.parallel_merge(children.top());
      children.pop();
    }

    acc.vertical_merge(fruits[i]);
    memo.push(acc);
  }

  ll res = 0;
  for (auto [t, w]: memo.top().m)
    res += w;
  return res;
}
