#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
   int n, m, e, a, b;
   vector<int> v;
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> e;
      v.push_back(e);
   }
   vector<int> tree (2 * n, 0);
   copy(v.begin(), v.end(), tree.begin() + n);
   for (int i = n; i > 0; i--) {
      tree[i] = max(tree[2 * i], tree[2 * i + 1 | 1]);
   }
   cin >> m;
   for (int i = 0; i < m; i++) {
      cin >> e >> a >> b;
      if (e == 0) { // update
         a += n;
         tree[a] = b;
         for (a /= 2; a >= 1; a /= 2) {
            tree[a] = max(tree[2 * a], tree[2 * a + 1 | 1]);
         }
      }
      else { // query
         a += n; b += n;
         int res = 0;
         while (a <= b) {
            if (a % 2 == 1) res = max(res, tree[a++]);
            if (b % 2 == 0) res = max(res, tree[b--]);
            a /= 2; b /= 2;
         }
         cout << res << endl;
      }
   }
}