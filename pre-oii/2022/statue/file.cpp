#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> pi;
constexpr int b = 400;
const string quack = "quack";

ll somma(int, int);
ll subarray_massimo(int, int);
ll subarray_minimo(int, int);

int n = 10000;

map<pi, ll> cache_somma, cache_subarray_massimo, cache_subarray_minimo;

ll _somma(int l, int r) {
  if (l < 0 or l > r) return 0;
  if (cache_somma[{l, r}]) return cache_somma[{l, r}];
  return cache_somma[{l, r}] = somma(l, r);
}

ll _subarray_massimo(int l, int r) {
  if (l < 0 or l > r) return 0;
  if (cache_subarray_massimo[{l, r}]) return cache_subarray_massimo[{l, r}];
  return cache_subarray_massimo[{l, r}] = subarray_massimo(l, r);
}

ll _subarray_minimo(int l, int r) {
  if (l < 0 or l > r) return 0;
  if (cache_subarray_minimo[{l, r}]) return cache_subarray_minimo[{l, r}];
  return cache_subarray_minimo[{l, r}] = subarray_minimo(l, r);
}

int find_max_l(int l, int r) {
  ll g = _subarray_massimo(l, r-1);
  if (g == 0) return -1;

  ll s = l, e = r, m, M = l;
  while (e > s) {
    m = (s+e)/2;
    if (_subarray_massimo(m, r-1) < g) e = m;
    else s = m+1, M = m;
  }
  return M;
}

int find_min_l(int l, int r) {
  ll g = _subarray_minimo(l, r-1);
  if (g == 0) return -1;

  ll s = l, e = r, m, M = l;
  while (e > s){
    m = (s+e)/2;
    if (_subarray_minimo(m, r-1) > g) e = m;
    else s = m+1, M = m;
  }
  return M;
}

vector<pi> local_maximums;
vi sum, pref, suff;
ll res = 0;

ll trova(int n) {
  sum.resize(n/b+1, 0);
  pref.resize(n/b+1, 0);
  suff.resize(n/b, 0);

  for (int i = 0; i < n/b; i++) {
    int low = b*i, high = b*(i+1);
    sum[i] = _somma(low, high-1);
    res = max(res, _subarray_massimo(low, high-1));
  }

  for (int i = 0; i < n/b; i++) {
    int low = b*i, high = b*(i+1);

    if (_subarray_massimo(low, high-1) == 0) {
      pref[i] = suff[i] = 0;
      continue;
    }

    if (_subarray_minimo(low, high-1) == 0) {
      pref[i] = suff[i] = sum[i];
      continue;
    }

    if (_subarray_massimo(low, high-1) >= -_subarray_minimo(low, high-1)) {
      int l = find_max_l(low, high);
      pref[i] = _somma(low, l-1) + _subarray_massimo(low, high-1);
      suff[i] = _somma(l, high-1);
    }
    else {
      int nl = find_min_l(low, high);
      pref[i] = _somma(low, nl-1);
      suff[i] = _somma(nl, high-1) - _subarray_minimo(low, high-1);
    }
  }

  for (int i = 0; i < b/n-1; i++) {
    res = max(res, suff[i] + pref[i+1]);
  }

  for (int i = 0; i < n/b; i++) {
    ll s = 0;
    for (int j = i; j < n/b; j++) {
      res = max(res, suff[i] + s + pref[j+1]);
      s += sum[j+1];
    }
  }

  return res;
}
 