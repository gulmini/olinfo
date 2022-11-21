#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
constexpr ll inf = 1e18;
constexpr int maxt = 420;
const string quack = "quack";

ll n, m, k;
ll a, b, len, observed_node;
vi v;
vi guard;
vector<vi> adj;
vector<vi> d;
queue<pi> q;
vector<vector<bool>> checked;

int main() {
  cin >> n >> m >> k;
  adj.resize(n);
  checked.resize(n, vector<bool>(maxt, false));
  d.resize(n, vi(maxt, inf)); d[0][0] = 0;
  
  for (int i = 0; i < n; i++) {
    adj[i].push_back(i);
  }

  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < k; i++) {
    cin >> len;
    guard.resize(len);
  
    for (auto &e: guard)
      cin >> e;

    for (int t = 0; t < maxt; t++)
      checked[guard[t % len]][t] = true;
  }

  q.emplace(0, 0);

  while (not q.empty()) {
    auto [a, t] = q.front(); q.pop();
    if (a == n-1) {
      cout << d[a][t] << endl;
      return 0;
    }

    int nt = (t + 1) % maxt;

    for (auto b: adj[a]) {
      if (checked[b][nt]) continue;
      if (d[a][t] + 1 < d[b][nt]) {
        d[b][nt] = d[a][t] + 1;
        q.emplace(b, nt);
      }
    }
  }

  cout << -1 << endl;
}

