#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef tuple<ll, ll, ll> ti;
constexpr ll inf = 1e18;
const string quack = "quack";

ll n, m;
ll a, b, s, e;
vi v, d;
vector<vector<ti>> adj;
ll start_node, end_node;
priority_queue<pi, vector<pi>, greater<pi>> q;

int main() {
  cin >> n;
  cin >> start_node >> end_node;
  cin >> m;

  adj.resize(n);
  d.resize(n, inf);
  d[start_node] = 0;

  for (int i = 0; i < m; i++) {
    cin >> a >> s >> b >> e;
    adj[a].push_back({b, s, e});
  }

  q.push({0, start_node});

  while (not q.empty()) {
    auto [_, nodo] = q.top(); q.pop();
    for (auto [nodo_arrivo, tempo_partenza, tempo_arrivo]: adj[nodo]) {
      if (d[nodo] > tempo_partenza) continue;
      if (tempo_arrivo < d[nodo_arrivo]) {
        q.push({d[nodo_arrivo] = tempo_arrivo, nodo_arrivo});
      }
    }
  }

  if (d[end_node] != inf) cout << d[end_node];
  else cout << "IMPOSSIBLE";

}

