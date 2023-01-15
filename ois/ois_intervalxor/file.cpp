#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll n, e;
vi v;

ll get_xorsum(ll n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}

int main() {
  cin >> n;
  v.resize(n);
  for (auto &e: v) cin >> e;

  for (int i = 0; i < n; i++) {
    ll xorsum = get_xorsum(v[i]);
    ll removing = 0;

    for (int j = 32-__builtin_clz(e)-1; j >= 0; j--) {
      if (not (1 & (xorsum >> j))) {
        removing |= 1 << j;
        if (removing > e)
          removing -= 1 << j;
      }
    }

    cout << xorsum << ' ' << (xorsum ^ removing) << endl;
  }

}

