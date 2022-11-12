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
ll res = -1;
vi positions;

struct antenna {
  ll i, treshold, potential, start, interval;
  antenna(): i(0), treshold(0), start(0), interval(0) {}
  antenna(int i, ll treshold, ll power, ll start, ll interval):
    i(i), treshold(treshold), potential(power), start(start), interval(interval) {}
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

ll calc(ll arrival_time, int i) {
  ll start = v[i].start;
  ll interval = v[i].interval;
  if (arrival_time < start) return start;
  return ((arrival_time - start) / interval + 1) * interval + start;
}

int main() {
  cin >> n >> decay_time;
  v.resize(n);
  potentials.reserve(n);
  tree.resize(2*n, inf);

  for (int i = 0; i < n; i++) {
    cin >> v[i].treshold >> v[i].potential >> v[i].start >> v[i].interval;
    v[i].treshold += i * decay_time;
    v[i].potential += i * decay_time;
    v[i].i = i;
  }

  for (int i = 0; i < n; i++) {
    potentials.push_back({ v[i].potential, i });
  }
  sort(potentials.begin(), potentials.end());

  upd(0, v[0].start);

  for (int i = 1; i < n; i++) {
    int query_pos = lower_bound(potentials.begin(), potentials.end(), pi{ v[i].treshold, -1 }) - potentials.begin();
    int update_pos = lower_bound(potentials.begin(), potentials.end(), pi{ v[i].potential, i }) - potentials.begin();
    ll arrival_time = qry(query_pos, n);
    ll send_time = calc(arrival_time, i);
    upd(update_pos, send_time);
    if (i == n-1)
      cout << (send_time < inf ? send_time : -1) << endl;
  }
}

