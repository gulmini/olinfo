#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef tuple<ll, ll, ll> ti;
const string quack = "quack";

ll n, m, q, a, b, w;
vi p, res, h;
vector<pi> v;
vector<ti> edges;

int find(int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

bool join(int x, int y) {
  int a = find(x);
  int b = find(y);
  if (a == b) return false;
  if (h[a] > h[b]) swap(a, b);
  if (h[a] == h[b]) h[b]++;
  p[a] = b;
  return true;
}

int main() {
  cin >> n >> m >> q;
  h.resize(n);
  p.resize(n);
  v.resize(q);
  res.assign(q, n);
  edges.resize(m);
  iota(p.begin(), p.end(), 0);
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> w, a--, b--;
    edges[i] = { w, a, b };
  }
  sort(edges.begin(), edges.end(), greater<ti>());

  for (int i = 0; i < q; i++) cin >> v[i].first, v[i].second = i;
  sort(v.begin(), v.end(), greater<pi>());

  int i = 0;
  
  for (auto [w, a, b]: edges) {
    while (w < v[i].first) {
      i++;
      if (i == q) break;
      res[v[i].second] = res[v[i-1].second];
    }
    res[v[i].second] -= join(a, b);
  }

  while (++i < q) {
    if (i) res[v[i].second] = res[v[i-1].second];
  }

  for (auto e: res) cout << e << '\n';
}

