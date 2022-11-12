#include <bits/stdc++.h>
using namespace std;
const string quack = "quack";

int n, k, res = 0, curr = 0;
vector<int> v;

int main() {
   cin >> n >> k; k--;
   v.resize(n);
   for (int i = 0; i < n; i++) {
      cin >> v[i]; v[i]--;
   }
   while (res <= n+1) {
      if (curr == k) break;
      res++;
      curr = v[curr];
   }
   cout << ((res > n) ? -1 : res);
}