#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef vector<int> vi;
typedef function<int(int, int)> lambda;
constexpr int maxn = 3000;

int n;
vi d;
vi processed, visited;
priority_queue<int, vi, lambda> q([](int a, int b) { return d[a] > d[b]; });

vector<tuple<int, int, string>> path;
vector<pair<lambda, string>> operators = {
  { lambda([](int a, int b) { return a << b; }), "<<" },
  { lambda([](int a, int b) { return a + b;  }), "+"  },
  { lambda([](int a, int b) { return a * b;  }), "*"  },
  { lambda([](int a, int b) { return a - b;  }), "-"  },
  { lambda([](int a, int b) { return a / b;  }), "/"  }
};

string build(int i) {
  if (i == 1) return "1";
  auto [a, b, op] = path[i];
  return "(" + build(a) + ")" + op + "(" + build(b) + ")";
}

void update(int i, int j, lambda f, string s) {
  int x = f(i, j);
  if (x <= 0 or x > maxn or visited[x]) return;
  if (d[i] + d[j] + 1 < d[x])
    d[x] = d[i] + d[j] + 1,
    path[x] = { i, j, s },
    q.push(x);
};

int main() {
  cin >> n;
  d.resize(maxn+1, 1e9); d[1] = 0;
  path.resize(maxn+1);
  visited.resize(maxn+1);

  q.push(1);
  processed.push_back(1);

  while (not q.empty()) {
    int i = q.top(); q.pop();

    if (i == n) break;
    processed.push_back(i);
    visited[i] = true;

    for (auto [f, s]: operators)
      for (int j: processed)
        update(i, j, f, s),
        update(j, i, f, s);
  }

  cout << build(n) << endl;
}

