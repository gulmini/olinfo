#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef set<ll> si;
typedef tuple<ll, ll, ll> edge;
const string quack = "quack";

ll n, m, a, b, w, cn = 0;
vi p, h;

vector<edge> edges;
vector<pair<int, int>> useful;

ll find(ll x) {
   return p[x] == x ? x : p[x] = find(p[x]);
}

bool join(ll x, ll y) {
   ll a = find(x);
   ll b = find(y);
   if (a == b) return false;
   if (h[a] < h[b]) swap(h[a], h[b]);
   p[b] = a;
   if (h[a] == h[b]) h[b]++;
   return true;
}

int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

   cin >> n >> m;
   p.resize(n+1);
   iota(p.begin(), p.end(), 0);
   h.resize(n+1, 1);
   edges.reserve(m);
   useful.reserve(n-1);

   for (int i = 0; i < m; i++) {
      cin >> a >> b >> w;
      edges.push_back({ a, b, w });
   }

   sort(edges.begin(), edges.end());
   ll res = 0;

   for (auto [a, b, w]: edges) {
      if (join(a, b)) {
         res += w;
         useful.push_back({ a, b });
      }
   }

   cout << res << "\n";
   for (auto &p: useful) {
      cout << p.first << " " << p.second << "\n";
   }
}
