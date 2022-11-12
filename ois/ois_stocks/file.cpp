#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string quack = "quack";

int n;
bool b;

int main() {
   cin >> n;
   vector<int> v(n);
   for (int i = 0; i < n; i++) cin >> v[i];

   for (int i = 0; i < n; i++) {
      cin >> b;
      v[i] = b * v[i];
   }

   ll res = v[0];
   ll c = v[0];

   for (int i = 1; i < n; i++) {
      if (v[i-1] > v[i]) c = 0;
      c += v[i];
      res = max(res, c);
   }

   cout << res << endl;
}
