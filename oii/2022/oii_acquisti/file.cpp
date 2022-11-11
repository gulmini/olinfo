#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
constexpr int maxn = 1e5;
const string quack = "quack";

array<ll, maxn> weight, pref;

vi calcola(int n, int q, vi quantity, vi capacity) {
  pref[0] = quantity[0];
  for (int i = 1; i < n; i++) {
    weight[i] = weight[i-1] + i * quantity[i];
    pref[i] = pref[i-1] + quantity[i];
  }
  for (auto &e: capacity) {
    int pos = prev(upper_bound(weight.begin(), weight.begin() + n, e)) - weight.begin();
    e = pos >= n-1 ? pref[n-1] : pref[pos] + (e - weight[pos]) / (pos+1);
  }
  return capacity;
}