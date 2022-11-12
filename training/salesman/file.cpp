#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef unsigned long long ull;

int n, m, a, b, w;
int tsp(int a, ull s, vector<vi> & M) {
   ull set_a = 1ULL << a;
   if (s == set_a) {
      return M[a][0];
   }
   
   ull intersection = (s&(~i));
   int res = INT32_MIN;

   for (int i = 1; i < (1 << n); i << 1) {
      if (s & i)
         res = min(res, M[a][i] + tsp(i, intersection, M));
   }
   return res;
}

int main() {
   cin >> n >> m;
   vector<vi> M(n, vi(n, INT32_MAX));
   for (int i = 0; i < m; i++) {
      cin >> a >> b >> w;
      M[a][b] = w;
   }
   cout << tsp(0, (1 << (n+1)) - 1, M) << endl;
}