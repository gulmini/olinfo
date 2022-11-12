#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
constexpr int maxn = 10003;
const string quack = "quack";

vi v, res, pref;
bool memo[maxn][maxn], calculated[maxn][maxn];

bool valid(int l, int r) {
  return pref[r] == (pref[l] ^ v[l]);
}

bool dp(int a, int b) {
  if (calculated[a][b]) return memo[a][b];
  calculated[a][b] = true;
  if (not valid(a, b)) return (memo[a][b] = false);

  for (int c = a; c <= b; c += 3) {
    if ((dp(a+1, c) and dp(c+2, b-1)) or (dp(a, c+2) and dp(c+3, b))) {
      return (memo[a][b] = true);
    }
  }

  return (memo[a][b] = false);
}

int conta(int n, vector<int> v) {
  clock_t tbegin = clock();
  ::v = move(v);

  pref.resize(n), pref[0] = ::v[0];
  res.resize(n+3);

  for (int i = 1; i < n; i++) pref[i] = pref[i-1] ^ ::v[i];
  for (int i = 1; i < n; i++)   calculated[i][i-1] = true, memo[i][i-1] = true;
  for (int i = 0; i < n-2; i++) calculated[i][i+2] = true, memo[i][i+2] = valid(i, i+2);

  for (int len = 6; len <= n; len += 3) {
    if (clock() >= tbegin + 0.6 * CLOCKS_PER_SEC) break;

    for (int a = 0; a + len - 1 < n; a++)
      dp(a, a + len - 1);
  }

  for (int i = n-2; i >= 0; i--) {
    res[i] = res[i+1];

    for (int j = i+2; j < n; j += 3)
      if (memo[i][j])
        res[i] = max(res[i], res[j+1] + (j - i + 1));
  }

  return res[0];
}
