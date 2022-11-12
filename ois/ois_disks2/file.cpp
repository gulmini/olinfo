#include <bits/stdc++.h>
using namespace std;
const string quack = "quack";

int n, t, a, b;

int main() {
   cin >> n >> t;
   vector<int> delta(n, INT32_MIN);
   vector<int> v;
   for (int i = 0; i < n; i++) {
      cin >> a >> b;
      v.push_back(a+24*i);
      v.push_back(b+24*i);
   }
   v.push_back(24*n);
   for (int i = 0; i < n-1; i++) {
      delta[i] = v[2*i+2] - v[2*i+1];
   }
   for (int i = 0; i < n; i++) {
      if (delta[i] >= t) {
         cout << i << endl;
         return 0;
      }
   }
   cout << -1 << endl;
}