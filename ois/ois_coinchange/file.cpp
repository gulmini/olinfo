#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll, 15> i15;
const int n = 15;
const string quack = "quack";

i15 val = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};
i15 v, res;
ll sum = 0;

int main() {
   for (int i = 0; i < n; i++)
      cin >> v[i];
   for (int i = 0; i < n; i++)
      sum += v[i] * val[i];
   for (int i = n-1; i >= 0; i--) {
      res[i] = sum / val[i];
      sum %= val[i];
   }
   for (auto e: res) cout << e << " ";
}