#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

vector<bool> checked;

ll dp(vi v, int l, int r, int lp, int rp) {
   // cout << "here l = " << l << ", r = " << r << endl;
   if (rp - lp == 1) return 0;
   if (r <= l) {
      if (checked[l]) return 0;
      else { 
         // cout << "added " << rp - lp << endl;
         return rp - lp;
      }
   }
   // cout << "added " << rp - lp << endl;

   int best = v[l+1] - lp;
   int m = l;
   for (int i = l+2; i <= r; i++) {
      if (best < v[i] - v[i-2])
      best = v[i] - v[i-2];
      m = i-1;
   }
   if (best < rp - v[r-1]) m = r;

   // cout << "m = " << m << endl;
   checked[m] = true;
   return rp - lp + dp(v, l, m-1, lp, v[m]) + dp (v, m, r, v[m]+1, rp);
}


int main() {
   int n, size;
   cin >> n >> size;
   vi v(n);
   checked.resize(n);
   fill(checked.begin(), checked.end(), false);
   for (int i = 0; i < n; i++) cin >> v[i];
   cout << dp(v, 0, n-1, 0, size) << endl;
}