#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int n, size;
vi v;
vector<bool> checked;

ll dp(vi v, int l, int r, int lp, int rp) {
   if (rp - lp == 1) return 0;
   if (r <= l) {
      if (checked[l]) return 0;
      else return rp - lp;
   }

   int best = v[l+1] - lp;
   int m = l;

   for (int i = l+2; i <= r; i++) {
      if (best < v[i] - v[i-2])
      best = v[i] - v[i-2];
      m = i-1;
   }

   if (best < rp - v[r-1]) m = r;

   checked[m] = true;
   return rp - lp + dp(v, l, m-1, lp, v[m]) + dp (v, m, r, v[m]+1, rp);
}

int main() {
   cin >> n >> size;
   v.resize(n);
   checked.resize(n);
   for (int i = 0; i < n; i++) cin >> v[i];

   cout << dp(v, 0, n-1, 0, size) << endl;
}