#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, m, k, q;
ll a, b;

struct exercise {
  ll n, d;
  exercise(): n(0), d(0) {}
  exercise(ll n, ll d): n(n), d(d) {}

  exercise operator+(exercise &e) {
    return exercise(n + e.n, d + e.d);
  }
  exercise operator-(exercise &e) {
    return exercise(n - e.n, d - e.d);
  }
  bool operator>(exercise &e) {
    return n * e.d > e.n * d;
  }
};

vector<exercise> v;

int main() {
  cin >> n;
  v.resize(n);
  exercise sum;

  for (int i = 0; i < n; i++) {
    cin >> v[i].n >> v[i].d;
  }

  for (int i = 0; i < n; i++) {
    sum = sum + v[i];
  }

  ll res = 0;
  exercise best = sum - v[0];

  for (int i = 0; i < n; i++) {
    if (sum - v[i] > best) {
      best = sum - v[i];
      res = i;
    }
  }

  cout << res << endl;
  
}

