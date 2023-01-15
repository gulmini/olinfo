#include <bits/stdc++.h>
using namespace std;
const string quack = "quack";

int n;
string s;
vector<array<int, 100>> memo;

int dp(int i, int swp) {
  if (i == n) return 0;
  if (memo[i][swp]) return memo[i][swp];

  int pos = i ? s[i-1]-'0' : 0;
  int dest = s[i]-'0';

  if (swp) {
    if (dest == swp / 10) dest = swp % 10;
    else if (dest == swp % 10) dest = swp / 10;

    if (pos == swp / 10) pos = swp % 10;
    else if (pos == swp % 10) pos = swp / 10;
  }

  int res = dp(i+1, swp) + abs(pos - dest);

  if (not swp) {
    for (int swap_term = 0; swap_term < 10; swap_term++) {
      if (swap_term == dest) continue;
      res = min(res, dp(i+1, swap_term*10+dest) + abs(pos-swap_term));
    }
  }

  return memo[i][swp] = res;
}

void solve() {
  cin >> s;
  n = s.size();

  memo.clear();
  memo.resize(n);

  cout << dp(0, 0) << endl;
}

int main() {
  int T; cin >> T;
  while (T--) solve();
}

