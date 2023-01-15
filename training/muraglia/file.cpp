#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
constexpr int inf = 1e9+1;
const string quack = "quack";

int n, m, k, q;
int sz;
vi v;
vi tree;

void _upd(int i, int l, int r, int pos, int val) {
  if (l == r) {
    tree[i] = val;
    return;
  }
  int m = (l + r) / 2;
  if (pos <= m) _upd(2*i, l, m, pos, val);
  else _upd(2*i+1, m+1, r, pos, val);
  tree[i] = max(tree[2*i], tree[2*i+1]);
}

int low(int i, int l, int r, int pos) {
  if (l > pos or tree[i] <= v[pos]) return -1;
  if (l == r) return l;
  int m = (l+r) / 2;
  int res = low(2*i+1, m+1, r, pos);
  if (res == -1)
    res = low(2*i, l, m, pos);
  return res;
}

int up(int i, int l, int r, int pos) {
  if (r < pos or tree[i] <= v[pos]) return inf;
  if (l == r) return l;
  int m = (l+r) / 2;
  int res = up(2*i, l, m, pos);
  if (res == inf)
    res = up(2*i+1, m+1, r, pos);
  return res;
}

void inizializza(int n, vi h) {
  v = move(h);
  sz = n;

  while (__builtin_popcount(sz) != 1) {
    sz++; v.push_back(-1);
  }

  tree.resize(2*sz);

  for (int i = 0; i < sz; i++)
    tree[sz+i] = v[i];

  for (int i = sz-1; i >= 1; i--)
    tree[i] = max(tree[2*i], tree[2*i+1]);

  ::n = n;
}

void cambia(int x, int h) {
  v[x] = h;
  _upd(1, 0, sz-1, x, h);
}

pi chiedi(int x) {
  return {
    max(0, low(1, 0, sz-1, x)),
    min(n-1, up(1, 0, sz-1, x))
  };
}
