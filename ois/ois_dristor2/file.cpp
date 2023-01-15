#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
constexpr int maxm = 100;
constexpr int mod = 1e9+7;
constexpr int max2n = 1 << 14;

#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
void debug_out() { cout << "\n"; }
template <typename T> ostream& operator<<(ostream& o, vector<T>& v) { for (auto e: v) cout << e << " "; cout << endl; return o; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cout << " " << H; debug_out(T...); }

ll n, m;
char c;
vector<vi> adj;
uint32_t max_memo[maxm+1][max2n];
uint64_t memo[maxm+1][max2n];
ll max_coverage, res = 0;

static uint32_t get_max(uint8_t j, uint16_t bitmask) {
  if (j == m) return __builtin_popcount(bitmask);
  if (max_memo[j][bitmask]) return max_memo[j][bitmask];

  uint32_t res = 0;
  for (auto i: adj[j])
    res = max(res, get_max(j+1, bitmask | 1 << i));

  res = max(res, get_max(j+1, bitmask));

  return max_memo[j][bitmask] = res;
}

static uint64_t dp(uint8_t j, uint16_t bitmask) {
  if (j == m) return __builtin_popcount(bitmask) == max_coverage;
  if (memo[j][bitmask]) return memo[j][bitmask];

  uint64_t res = 0;
  for (auto i: adj[j])
    if (not (1 & (bitmask >> i)))
      res += dp(j+1, bitmask | 1 << i);

  res += dp(j+1, bitmask);

  return memo[j][bitmask] = res % mod;
}

int main() {
  cin >> n >> m;
  adj.resize(m+1);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c;
      if (c == '1')
        adj[j].push_back(i);
    }
  }

  max_coverage = get_max(0, 0);

  for (int bitmask = 0; bitmask < (1 << n); bitmask++) {
    memo[m][bitmask] = __builtin_popcount(bitmask) == max_coverage;
  }

  for (int j = m-1; j >= 0; j--) {
    for (int bitmask = 0; bitmask < (1 << n); bitmask++) {
      for (auto i: adj[j]) {
        if (not (1 & (bitmask >> i)))
          memo[j][bitmask] += memo[j+1][bitmask | 1 << i],
          memo[j][bitmask] %= mod;
      }
      memo[j][bitmask] += memo[j+1][bitmask],
      memo[j][bitmask] %= mod;
    }
  }

  cout << memo[0][0] << endl;

  // for (int j = 0; j < m; j++) {
  //   for (int i = 0; i < (1 << n); i++) {
  //     cout << memo[j][i] << ' ';
  //   }
  //   cout << endl;
  // }
}

