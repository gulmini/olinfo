#include <bits/stdc++.h>
using namespace std;
constexpr int inf = 1e9+1;
const string quack = "quack";

int n, e, res = 0;
vector<int> v;
map<int, int> m;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> n;
  v.resize(n);

  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) cin >> e, v[i] = e - v[i];

  partial_sum(v.begin(), v.end(), v.begin());

  for (int i = 0; i < n; i++) m[v[i]] = i;
  m[inf] = -inf;

  for (auto it = next(m.rbegin()); it != m.rend(); it++)
    it->second = max(it->second, prev(it)->second);

  for (int i = 0; i < n; i++) {
    int end = m.lower_bound(i ? v[i-1] : 0)->second;
    res = max(res, end-i+1);
  }

  cout << res << endl;
}
