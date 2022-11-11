#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const string quack = "quack";

ll res = 0;
ll c[32];

inline void add_truck(ll w) {
   for (int j = 0; j < 31; j++)
      if (1 & (w >> j)) c[j]++;
}

inline void collapse(ll req, int base, int pos) {
   if (pos == 31) return;
   ll q = c[pos] << (pos-base);
   c[pos] = 0;
   if (req > q) {
      req -= q;
      res += q;
      collapse(req, base, pos+1);
   }
   else {
      res += req;
      ll x = (q-req) << base;
      c[pos] = x >> pos;
      add_truck(x % (1 << pos));
   }
}

ll riciclo(int n, int m, vi t, vi p) {
   for (auto &e: t) add_truck(e);
   for (int j = 0; j < m; j++) collapse(p[j], j, j);
   return res;
}
