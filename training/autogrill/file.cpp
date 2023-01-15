#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
constexpr ll inf = 1ll << 62;

#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
void debug_out() { cout << "\n"; }
template <typename T> ostream& operator<<(ostream& o, vector<T>& v) { for (auto e: v) cout << e << " "; cout << endl; return o; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cout << " " << H; debug_out(T...); }

ll n, m, k, q;
set<ll> s;

void inizia() {}
void apri(long long p) { s.insert(p); }
void chiudi(long long p) { s.erase(p); }
long long chiedi(long long p) {
  if (s.empty()) return -1;
  auto it = s.lower_bound(p);
  ll best = -inf;
  if (it != s.begin()) best = *prev(it);
  if (it != s.end() and abs(p - best) >= abs(p - *it)) best = *it;
  return best == -inf ? -1 : best;
}


