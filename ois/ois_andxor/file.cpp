#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<ll, 21> i21;
const string quack = "quack";

ll n, q, i, x;
vector<ll> v;
vector<i21> b;
i21 xorsums, bits;

void update(int i, int x) {
   for (int j = 0; j < 21; j++)
      if (1 & (v[i] >> j))
         b[i][j]--, bits[j]--, xorsums[j] ^= v[i];

   v[i] = x;

   for (int j = 0; j < 21; j++)
      if (1 & (v[i] >> j))
         b[i][j]++, bits[j]++, xorsums[j] ^= v[i];
}

ll query() {
   ll res = -1;
   for (int j = 0; j < 21; j++)
      res = max(res, bits[j]);
   for (int j = 0; j < 21; j++)
      if (bits[j] == res and xorsums[j])
         return res;
   return res-1;
}

int main() {
   cin >> n >> q;
   v.resize(n);
   b.resize(n);
   for (int i = 0; i < n; i++) cin >> v[i];

   for (int i = 0; i < n; i++)
      for (int j = 0; j < 21; j++)
         if (1 & (v[i] >> j))
            b[i][j]++, bits[j]++, xorsums[j] ^= v[i];

   while (q--) {
      cout << query() << endl;
      cin >> i >> x; i--;
      update(i, x);
   }
   cout << query() << endl;
}
