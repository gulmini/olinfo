#include <bits/stdc++.h>
using namespace std;
typedef uint_fast32_t ll;
typedef vector<ll> vi;
typedef array<ll, 2> i2;
constexpr ll inf = 1e9;
constexpr ll h = 2001;
const string quack = "quack";

ll n, ans = inf;
ll calls;
vi a;
vector<vector<i2>> memo;

inline ll p(int x, int y) { return (x - y) * (x - y); }

ll dp() {
   for (int c = 0; c < h; c++) {
      ll d = p(a[0], c);
      memo[0][c] = i2{d, d};
   }
   for (int i = 1; i < n; i++) {
      memo[i][h-1][0] = memo[i][0][1] = inf;
      ll minprev = inf;
      for (int c = h-2; c >= 0; c--) {
         minprev = min(minprev, memo[i-1][c+1][1]);
         memo[i][c][0] = p(a[i], c) + minprev;
      }
      minprev = inf;
      for (int c = 1; c < h; c++) {
         minprev = min(minprev, memo[i-1][c-1][0]);
         memo[i][c][1] = p(a[i], c) + minprev;
      }
   }
   ll res = inf;
   for (int c = 0; c < h; c++) {
      res = min(res, memo[n-1][c][0]);
      res = min(res, memo[n-1][c][1]);
   }
   return res;
}

int main() {
   cin >> n;
   a.resize(n);
   memo.resize(n, vector<i2> (h+1, i2{0, 0}));
   for (int i = 0; i < n; i++) cin >> a[i];

   cout << dp() << endl;
}
