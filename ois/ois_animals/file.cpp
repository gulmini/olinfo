#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll n;
vi v;
stack<int> s;

int main() {
  cin >> n;
  v.resize(n);
  for (auto &e: v) cin >> e;

  for (int i = 0; i < n; i++) {
    while (not s.empty() and v[i] > s.top()) s.pop();
    s.push(v[i]);
  }

  cout << s.size() << endl;
}

