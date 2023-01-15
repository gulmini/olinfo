#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll n, m, k, q;
vi v;
vi freq;
ll distinct = 0;

void extend(int i) {
  freq[v[i]]++;
  if (freq[v[i]] == 1) distinct++;
}

void retract(int i) {
  freq[v[i]]--;
  if (freq[v[i]] == 0) distinct--;
}

int main() {
  cin >> n >> k;
  v.resize(n);
  freq.resize(k);
  for (auto &e: v) cin >> e;

  for (int i = 0; i < n; i++) extend(i);

  int r = n-1;
  int l = 0;

  while (distinct == k) retract(r--);
  extend(++r);

  while (distinct == k) retract(l++);
  extend(--l);

  cout << r - l + 1 << endl;
}
