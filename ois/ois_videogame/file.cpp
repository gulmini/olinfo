#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, m, k;
vector<pi> a, b;

ll res = 0;

int main() {
  cin >> k;

  cin >> n;
  a.resize(n);
  for (auto &[x, y]: a) cin >> x >> y; 

  sort(a.begin(), a.end());

  cin >> m;
  b.resize(m);
  for (auto &[x, y]: b) cin >> x >> y;

  sort(b.begin(), b.end());

  deque<pi> qa;
  deque<pi> qb;

  for (auto p: a) qa.push_back(p);
  for (auto p: b) qb.push_back(p);

  while (not qa.empty() and not qb.empty()) {
    auto &[start_a, end_a] = qa.front();
    auto &[start_b, end_b] = qb.front();

    if (end_b < start_a) {
      qb.pop_front();
      continue;
    }

    if (end_a < start_b) {
      qa.pop_front();
      continue;
    }

    if (start_b - start_a > k) {
      qa.pop_front();
      continue;
    }

    int time_together = min(end_a, end_b) - max(start_a, start_b) + 1;

    if (end_a > end_b) {
      start_a = end_b + 1;
    }

    res += max(0, time_together);

    if (end_a < end_b) qa.pop_front();
    else qb.pop_front();
  }

  cout << res << endl;

}

