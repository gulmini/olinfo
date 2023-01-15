#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const string quack = "quack";

vi res, v, max_load;
int n, t, k;

vector<int> cucina(int n, int k, int t, vector<int> arrival) {
  ::t = t, ::n = n, ::k = k;
  res.resize(t+1);
  v.resize(t);
  max_load.resize(t+1);

  for (int i = 0; i < n; i++) v[arrival[i]]++;

  max_load[t] = k-1;
  for (int i = t-1; i >= 0; i--) {
    int extra_load = min(k-max_load[i+1], v[i]);
    max_load[i] = max(0, max_load[i+1] + extra_load - 1);
    res[i] = extra_load + res[i+1];
  }

  res.pop_back();
  return res;
}