#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll n, m, k, q;
vi v;
bitset<10> vis;

void reset() {
  vis = 0;
}

void update(ll k) {
  while (k) {
    vis[k%10] = 1;
    k /= 10;
  }
}

ll solve(ll k) {
  ll res = 0;
  while (vis.count() != 10) {
    update(k * (res+1));
    res++;
  }
  return res;
}

int main() {
  cin >> q;
  while (q--) {
    cin >> k;
    cout << solve(k) << endl;
    reset();
  }
}

