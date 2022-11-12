#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll INF = INT64_MAX/4;
const string quack = "quack";

int n, m, t, a, b, w;
bool e;

struct Edge {
   ll b, w;
   bool e;
};

vector<vector<Edge>> adj;
vector<ll> d;
vector<bool> visited;

int main() {
   cin >> n >> m >> t;
   adj.resize(n);
   visited.resize(n, false);
   d.resize(n, INF); d[0] = 0;
   for (int i = 0; i < m; i++) {
      cin >> a >> b >> w; cin >> e;
      adj[a].push_back(Edge{b, w, e});
   }
   priority_queue<pi, vector<pi>, greater<pi>> q;
   q.push(pi{0, 0});
   while (not q.empty()) {
      auto [v, a] = q.top(); q.pop();
      if (visited[a]) continue;
      visited[a] = true;
      for (Edge u: adj[a]) {
         ll b = u.b, w = u.w;
         bool e = u.e;
         if (e and d[a] + w > t) continue;
         if (d[a] + w < d[b]) {
            d[b] = d[a] + w;
            q.push({d[b], b});
         }
      }
   }
   if (d[n-1] == INF) cout << -1;
   else cout << d[n-1];
}