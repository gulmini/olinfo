#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef array<ll, 3> i3;
constexpr ll trigger = -1e18+1;
const string quack = "quack";

ll n, m, k, q;
vi v;
vector<vector<i3>> memo;

ll dp(int i, int j, int consec) {
  if (consec == 3) return dp(i, j-1, 0);
  if (memo[i][j][consec] != trigger) return memo[i][j][consec];
  if (j == 0) return 0;
  ll res = trigger;

  for (int l = 3; l <= 11; l++) {
    res = max(res, dp((i + l) % n, j-1, 0) + v[(i+l)%n]);
  }

  for (int l = 2; l <= 12; l += 2) {
    res = max(res, dp((i + l) % n, j, consec+1) + v[(i+l)%n]);
  }
  
  return memo[i][j][consec] = res;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  v.resize(n);
  memo.resize(n, vector<i3>(k+1, i3{trigger, trigger, trigger}));
  for (int i = 0; i < n; i++) cin >> v[i];
  cout << dp(0, k, 0) << endl;
}

