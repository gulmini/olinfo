#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
constexpr ll modulo = 1e9+7;
const string quack = "quack";

ll n, k, res = 0;
vi v;
vector<vi> memo, pref;
list<int> decreasing;

ll query(int l, int r, int k) {
  return l
    ? (pref[r][k] - pref[l-1][k] + modulo) % modulo
    : pref[r][k];
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  memo.resize(n+1, vi(k+1));
  pref.resize(n+1, vi(k+1));

  for (int i = 0; i <= n; i++)
    memo[i][0] = pref[i][0] = 1;

  for (int i = 1; i <= n; i++) {
    pref[i][0] = pref[i-1][0] + memo[i][0];
    for (int j = 1; j <= k; j++) {
      memo[i][j] = (memo[i-1][j] + pref[i-1][j-1]) % modulo;
      pref[i][j] = (pref[i-1][j] + memo[i][j]) % modulo;
    }
  }

  decreasing.insert(decreasing.begin(), n);

  for (int i = n-1; i >= 0; i--) {
    ll max_gcd = v[i];
    decreasing.insert(decreasing.begin(), i);

    for (auto it = next(decreasing.begin()); it != decreasing.end(); it++) {
      ll gcd = *it == n ? 0 : __gcd(max_gcd, v[*it]);
      if (gcd == max_gcd) {
        it--;
        decreasing.erase(next(it));
        continue;
      }

      for (int j = 0; j < k; j++) {
        res += (
          query(n-*it, n-*prev(it)-1, k-j-1) *
          max_gcd % modulo *
          memo[i][j] % modulo
        );
        res %= modulo;
      }

      max_gcd = gcd;
    }

    decreasing.insert(decreasing.begin(), i);
  }

  cout << res << endl;
}

