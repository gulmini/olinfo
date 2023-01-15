#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll n, days, type, w, res = 0;
vector<ll> v, capacity;

int main() {
  cin >> n >> days;
  capacity.resize(n);
  v.resize(n);

  for (int i = 0; i < n; i++)
    cin >> capacity[i];

  while (days--) {
    cin >> type >> w;
    if (v[type] + w > capacity[type]) {
      res += capacity[type] - v[type];
    }
    v[type] = w;
  }

  for (int i = 0; i < n; i++) {
    if (v[i] == 0) continue;
    res += capacity[i] - v[i];
  }

  cout << res << endl;
}

