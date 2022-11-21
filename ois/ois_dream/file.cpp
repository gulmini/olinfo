#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
constexpr ll mod = 666013;
constexpr ll maxn = 300000;
const string quack = "quack";

ll n, k, res = 0;
vi modpows;
vi v;
vi pows = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

int digit(int n, int k) {
  if (k > 6) return 0;
  return n / pows[k] % 10;
}

int main() {
  cin >> k >> n;
  modpows.resize(maxn);
  v.resize(maxn, 0);

  modpows[0] = 1;
  for (int i = 1; i <= n; i++)
    modpows[i] = modpows[i-1] * 10 % mod;

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < min(n/2, 6ll); j++) {
      v[n/2+j] += digit(i, j);
      v[n/2-j-1] += digit(i, j);
    }
  }

  for (int i = 0; i < k; i++)
    v[0] += 1 + digit(i, n/2);

  v[n-1] = v[0];

  for (int i = 0; i < maxn; i++) {
    res += modpows[i] * v[i] % mod;
    res %= mod;
  }

  cout << res << endl;
}

