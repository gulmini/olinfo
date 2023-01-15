#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n;
vector<pi> v;
multiset<pi> s;
ll res = 0;

int main() {
  cin >> n;
  v.resize(n);

  for (int i = 0; i < n; i++)
    cin >> v[i].first >> v[i].second;
  
  s = multiset<pi>(v.begin(), v.end());

  while (not s.empty()) {
    res++;
    multiset<pi>::iterator nxt;
    auto it = s.begin();

    while (not s.empty()) {
      auto [a, b] = *it;
      s.erase(it);
      nxt = s.lower_bound({b, -1});
      if (nxt == s.end() or nxt->first != b) break;
      it = nxt;
    }

  }
  cout << res << endl;
}

