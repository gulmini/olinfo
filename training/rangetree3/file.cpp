#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
constexpr ll inf = 1e14;

#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
void debug_out() { cout << "\n"; }
template <typename T> ostream& operator<<(ostream& o, vector<T>& v) { for (auto e: v) cout << e << " "; cout << endl; return o; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cout << " " << H; debug_out(T...); }

ll n, m, k, q;
vi v;
int type;
ll a, b;

struct node {
   ll l, r, s, g;
   node() {}
   node(ll val): l(val), r(val), s(val), g(val) {}
   node(node a, node b) {
      s = a.s + b.s;
      l = max(a.l, a.s + b.l);
      r = max(a.r + b.s, b.r);
      g = max(max(a.g, b.g), a.r + b.l);
   }
   node operator+(node o) {
      return node(*this, o);
   }
};

vector<node> tree;

void update(int i, int l, int r, int pos, int val) {
   if (l == r) {
      tree[i] = node(val);
      return;
   }
   int m = (l + r) / 2;
   if (pos <= m) update(2*i, l, m, pos, val);
   else update(2*i+1, m+1, r, pos, val);
   tree[i] = tree[2*i] + tree[2*i+1];
}

node query(int i, int l, int r, int a, int b) {
   if (r < a or l > b) return node(-inf);
   if (a <= l and r <= b) return tree[i];
   int m = (l + r) / 2;
   return query(2*i, l, m, a, b) + query(2*i+1, m+1, r, a, b);
}

int main() {
   cin >> n;
   v.resize(n);
   for (int i = 0; i < n; i++) cin >> v[i];
   cin >> q;
   
   while (__builtin_popcount(n) != 1)
      n++, v.push_back(-inf);

   tree.resize(2*n);

   for (int i = 0; i < n; i++)
      tree[n+i] = node(v[i]);
   for (int i = n-1; i >= 1; i--)
      tree[i] = tree[2*i] + tree[2*i+1];

   while (q--) {
      cin >> type >> a >> b;
      if (type == 0) {
         a--;
         update(1, 0, n-1, a, b);
      }
      else {
         a--, b--;
         cout << query(1, 0, n-1, a, b).g << endl;
      }
   }
}
