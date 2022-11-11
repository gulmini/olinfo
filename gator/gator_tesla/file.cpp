#include <bits/stdc++.h>
using namespace std;
const int INF = INT32_MAX / 4;

int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int n, e; cin >> n;
   vector<int> v(n);
   for (int i = 0; i < n; i++) {
      cin >> e;
      v[i] = e - 10;
      v.push_back(e - 10);
   }
   int sum = -INF;
   int best = -INF;
   int startpos = -1;
   int bestpos = -1;
   for (int i = 0; i < 2*n; i++) {
      if (v[i] > sum + v[i]) {
         sum = v[i];
         startpos = i;
      }
      else sum += v[i];
      if (sum > best) {
         best = sum;
         bestpos = startpos;
      }
   }
   cout << bestpos + 1;
}