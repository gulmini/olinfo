#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, m, k, a, b;
vi path, d;
vector<vi> adj;
queue<pi> q;

int main() {
  cin >> n >> m >> k;

  adj.resize(n);
  path.resize(k);
  d.resize(n, 1<<30); d[0] = 0;

  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < k; i++) {
    cin >> path[i];
  }

  q.push({ 0, 0 });

  while (not q.empty()) {
    auto [a, t] = q.front(); q.pop();

    if (a == n-1) {
      cout << t << endl;
      break;
    }

    for (auto b: adj[a]) {
      if (path[(t+1) % k] == b)
        q.push({ a, t+1 });
      else if (d[a] + 1 < d[b])
        q.push({ b, d[b] = t+1 });
    }
  }
}

