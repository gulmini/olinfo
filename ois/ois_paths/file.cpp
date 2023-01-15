#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
constexpr ll mod = 1e9+7;
constexpr ll lg = 20;
const string quack = "quack";

#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
void debug_out() { cout << "\n"; }
template <typename T> ostream& operator<<(ostream& o, vector<T>& v) { for (auto e: v) cout << e << " "; cout << endl; return o; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cout << " " << H; debug_out(T...); }

ll n, q, timer = 0;
vi v, p, highest, tin, tout;
ll a, b, cc;
vector<vi> adj, up;

ll pow2(int n) {
  if (n < 62) return (1ll << n) % mod;
  ll r = pow2(n/2);
  r = r * r % mod;
  return (n & 1) ? (r << 1) % mod : r;
}

void dfs(int i, int p) {
  up[i][0] = highest[i] = p;
  tin[i] = timer++;
  for (auto u: adj[i]) {
    if (u == p) continue;
    dfs(u, i);
  }
  tout[i] = timer;
}

inline bool anc(int u, int v) {
  return tin[u] <= tin[v] and tout[u] >= tout[v];
}

int lca(int u, int v) {
  if (anc(u, v)) return u;
  if (anc(v, u)) return v;
  for (int j = lg-1; j >= 0; j--) {
    if (not anc(up[u][j], v))
      u = up[u][j];
  }
  return up[u][0];
}

int find(int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

void join(int x, int y) {
  int a = find(x);
  int b = find(y);
  if (a == b) return;
  if (anc(highest[a], highest[b])) swap(a, b);
  p[a] = b;
}

void join_path(int a, int l) {
  int base = a;
  while (not anc(a, l)) {
    join(base, a);
    a = highest[find(a)];
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  adj.resize(n);
  tin.resize(n);
  tout.resize(n);
  highest.resize(n);
  p.resize(n); iota(p.begin(), p.end(), 0);
  up.resize(n, vi(lg));
  cc = n;

  for (int i = 0; i < n-1; i++) {
    cin >> a >> b, a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(0, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 1; j < lg; j++) {
      up[i][j] = up[up[i][j-1]][j-1];
    }
  }

  cin >> q;
  while (q--) {
    cin >> a >> b, a--, b--;
    int l = lca(a, b);

    join_path(a, l);
    join_path(b, l);
    if (a != l and b != l) {
      join(a, b);
    }
  }

  for (int i = 0; i < n; i++)
    find(i);
  
  bitset<300000> bs = 0;
  for (int i = 1; i < n; i++) {
    bs[p[i]] = 1;
  }
  cout << pow2(bs.count()) << endl;
}

