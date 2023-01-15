#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef tuple<ll, ll, ll> ti;
constexpr ll inf = 1ll << 50;
const string quack = "quack";

#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
void debug_out() { cout << "\n"; }
template <typename T> ostream& operator<<(ostream& o, vector<T>& v) { for (auto e: v) cout << e << " "; cout << endl; return o; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cout << " " << H; debug_out(T...); }

ll n, m;
vi v, d0, dn;
ll a, b, w;
vector<vector<pi>> adj;
vector<ti> edges;
vi prv, path;
ll mindist;

bool in_path(int i) {
  return d0[i] + dn[i] == mindist;
}

ll dijkstra(vi &d, int source, int dest) {
  priority_queue<pi, vector<pi>, greater<pi>> q;
  q.emplace(0, source);
  d.assign(n, inf); d[source] = 0;
  while (not q.empty()) {
    auto [_, a] = q.top(); q.pop();
    for (auto [b, w]: adj[a]) {
      if (d[a] + w < d[b]) {
        prv[b] = a;
        d[b] = d[a] + w;
        q.emplace(d[b], b);
      }
    }
  }
  return d[dest];
}

int main() {
  cin >> n >> m;
  adj.resize(n);
  d0.resize(n);
  dn.resize(n);
  path.resize(n, -1);
  prv.resize(n);

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> w;
    edges.emplace_back(a, b, w);
    adj[a].emplace_back(b, w);
    adj[b].emplace_back(a, w);
  }

  mindist = dijkstra(dn, n-1, 0);
  dijkstra(d0, 0, n-1);

  ll res = inf;

  for (auto [a, b, w]: edges) {
    if (in_path(a) and in_path(b)) continue;
    ll dist = min(
      d0[a] + dn[b],
      d0[b] + dn[a]
    ) + w;
    if (dist - w + 1 < mindist) {
      res = min(res, dist - mindist + 1);
    }
  }

  cout << (res == inf ? -1 : res) << endl;
}

