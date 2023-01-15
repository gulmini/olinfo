#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
constexpr int p = 31;
constexpr int mod = 1e9+7;
constexpr int maxn = 1e6;
constexpr int maxm = 1e6;

#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
void debug_out() { cout << "\n"; }
template <typename T> ostream& operator<<(ostream& o, vector<T>& v) { for (auto e: v) cout << e << " "; cout << endl; return o; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cout << " " << H; debug_out(T...); }

string s;
ll n, m, res = 0;
ll pows[2*maxm], invpows[2*maxm], prefix_hashes[2*maxm];
bool processed[maxn];
ll maxhashes[maxn];
map<ll, vi> hashes;

ll fast_exp(ll b, ll n) {
  if (n == 0) return 1;
  ll r = fast_exp(b, n/2);
  r = r * r % mod;
  return n % 2 ? b * r % mod : r;
}

ll inv(ll n) {
  return fast_exp(n, mod-2);
}

ll substring(int l, int r) {
  return (prefix_hashes[r] - (l ? prefix_hashes[l-1] : 0) + mod) % mod * invpows[l] % mod;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;

  pows[0] = invpows[0] = 1;
  for (int i = 1; i < 2*m; i++)
    pows[i] = pows[i-1] * p % mod,
    invpows[i] = inv(pows[i]);
  
  for (int i = 0; i < n; i++) {
    cin >> s;
    ll hash = 0;

    for (int j = 0; j < 2*m; j++) {
      hash += (s[j%m] - 'a' + 1) * pows[j] % mod;
      hash %= mod;
      prefix_hashes[j] = hash;
    }

    for (int j = 0; j < m; j++) {
      maxhashes[i] = max(maxhashes[i], substring(j, j+m-1));
    }
  }

  sort(maxhashes, maxhashes+n);
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    if (maxhashes[i] != maxhashes[i-1]) {
      res += cnt * (cnt - 1) / 2;
      cnt = 0;
    }
    cnt++;
  }
  res += cnt * (cnt - 1) / 2;

  for (auto [hash, indexes]: hashes) {
    if (processed[indexes[0]]) continue;
    int cnt = 0;
    for (auto i: indexes) {
      cnt += not processed[i];
      processed[i] = true;
    }
    res += cnt * (cnt - 1) / 2;
  }

  cout << res << endl;
}

