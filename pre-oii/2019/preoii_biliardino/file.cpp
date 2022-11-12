#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
constexpr int lg = 20;
constexpr int maxn = 1000001;
const string quack = "quack";

ll timer = 0;
int * v;
int tin[maxn], tout[maxn], p[maxn], up[maxn][lg];
ll d[maxn];
vi adj[maxn];
stack<pi> s;

void dfs(int i, ll dist = 0) {
  d[i] = dist;
  tin[i] = timer++;

  for (auto u: adj[i])
    dfs(u, dist + v[u] * (ll)(i - u));

  tout[i] = timer++;
}

bool anc(int u, int v) {
  return tin[u] <= tin[v] and tout[u] >= tout[v];
}

void inizia(int n, int T[]) {
  v = T;

  s.push({-1, n});

  for (int i = n-1; i >= 0; i--) {
    while (v[i] < s.top().first) s.pop();

    p[i] = s.top().second;
    adj[p[i]].push_back(i);
    up[i][0] = p[i];

    s.push({v[i], i});
  }

  for (int j = 0; j < lg; j++)
    up[n][j] = n;

  for (int j = 1; j < lg; j++)
    for (int i = 0; i < n; i++)
      up[i][j] = up[up[i][j-1]][j-1];

  dfs(n);
}

ll passaggio(int low, int last) {
  int high = low;

  for (int j = lg-1; j >= 0; j--)
    if (up[high][j] < last) high = up[high][j];

  return d[low] - d[high] + (last - high) * (ll)v[high];
}
