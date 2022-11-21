#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
constexpr ll inf = 1e17;
constexpr ll trigger = -1e17-1;
constexpr ll maxn = 200000;
const string quack = "quack";

ll n, m, k, q, a, b;
ll v[maxn];
vi adj[maxn];
array<ll, 2> memo[maxn];

ll dp(vector<pi> &figli, int i, bool b) {
  if (i == figli.size()) return - inf * b;
  if (memo[i][b] != trigger) return memo[i][b];
  return memo[i][b] = max(
    dp(figli, i+1, b) + figli[i].first,
    dp(figli, i+1, not b) + figli[i].second
  );
}

pi calculate(vector<pi> &figli, int i) {
  if (figli.empty())
    return { v[i], 0 };
  fill(memo, memo+figli.size(), array<ll, 2>({ trigger, trigger }));
  return { dp(figli, 0, 0) + v[i], dp(figli, 0, 1) };
}

pi dfs(int i, int p) {
  vector<pi> v;
  for (auto u: adj[i]) {
    if (u == p) continue;
    v.push_back(dfs(u, i));
  }
  return calculate(v, i);
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;

  for (int i = 0; i < n-1; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < n; i++) cin >> v[i];

  pi res = dfs(0, -1);
  cout << max(res.first, res.second) << endl;
}

