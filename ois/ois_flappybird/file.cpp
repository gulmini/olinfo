#include <bits/stdc++.h>
using namespace std;
constexpr int inf = 1e9;
const string quack = "quack";

int main() {
   int n, a, b;
   int l = 1, r = inf;
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> a >> b;
      if (r < a or l > b) {
         cout << "NO";
         return 0;
      }
      l = a;
      r = b;
   }
   cout << "YES";
}