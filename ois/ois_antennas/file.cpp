#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
constexpr ll inf = 1e18;
const string quack = "quack";

int n;
ll decay_time;
vi tree;
vector<pi> potentials;

struct antenna {
  ll i, threshold, potential, start, interval;
  antenna(): i(0), threshold(0), start(0), interval(0) {}
  antenna(int i, ll treshold, ll power, ll start, ll interval):
    i(i), threshold(treshold), potential(power), start(start), interval(interval) {}
};

vector<antenna> v;

ll qry(int l, int r) {
  ll res = inf;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = min(res, tree[l++]);
    if (r & 1) res = min(res, tree[--r]);
  }
  return res;
}

void upd(int i, ll val) {
  for (tree[i += n] = val; i > 1; i >>= 1)
    tree[i>>1] = min(tree[i], tree[i^1]);
}

ll calc(ll arrival_time, ll start, ll interval) {
  if (arrival_time < start) return start;
  return ((arrival_time - start) / interval + 1) * interval + start;
}

int main() {
  cin >> n >> decay_time;
  v.resize(n);
  potentials.resize(n);
  tree.resize(2*n, inf);

  for (int i = 0; i < n; i++) {
    cin >> v[i].threshold >> v[i].potential >> v[i].start >> v[i].interval;
    v[i].threshold += i * decay_time;
    v[i].potential += i * decay_time;
    v[i].i = i;
    potentials[i] = { v[i].potential, i };
  }

  sort(potentials.begin(), potentials.end());

  for (int i = 0; i < n; i++) {
    int query_pos = lower_bound(potentials.begin(), potentials.end(), pi{ v[i].threshold, -1 }) - potentials.begin();
    int update_pos = lower_bound(potentials.begin(), potentials.end(), pi{ v[i].potential, i }) - potentials.begin();
    ll arrival_time = i ? qry(query_pos, n) : 0;
    ll send_time = calc(arrival_time, v[i].start, v[i].interval);
    upd(update_pos, send_time);
    if (i == n-1)
      cout << (send_time >= inf ? -1 : send_time) << endl;
  }
}

