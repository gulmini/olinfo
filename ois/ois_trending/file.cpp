#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, string> ps;
const string quack = "quack";

int main() {
   int n, t;
   cin >> n >> t;
   string s, sr, sl;
   vector<string> v(n);
   map<int, set<string>> best;
   map<string, int> m;
   for (int i = 0; i < n; i++) cin >> v[i];

   int l = -1;
   for (int r = 0; r < n; r++) {
      sr = v[r];
      m[sr]++;
      best[m[sr]].insert(sr);
      best[m[sr] - 1].erase(sr);
      if (r >= t-1) {
         l++;
         sl = v[l];
         m[sl]--;
         cout << *(((--best.end())->second).begin()) << endl;
         best[m[sl]].insert(sl);
         best[m[sl] + 1].erase(sl);
         if (best[m[sl] + 1].empty()) best.erase(m[sl] + 1);
      }
   }
}