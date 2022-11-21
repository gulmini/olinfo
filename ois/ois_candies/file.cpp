#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, m, k, q;
vi v;
ll res = 1, cnt = 1, prv;

int main() {
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  sort(v.begin(), v.end());

  prv = v[0];

  for (int i = 1; i < n; i++) {
    if (v[i] != prv) cnt++;
    res += cnt;
    prv = v[i];
  }

  cout << res << endl;
}

