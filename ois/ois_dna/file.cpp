#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef bitset<100> bs;
const int inf = INT32_MAX / 4;
const string quack = "quack";

int n, m;
string s;
vector<bs> g;
vector<bool> visited;

inline int dist(int a, int b) {
   return (g[a] ^ g[b]).count();
}

int main() {
   cin >> n >> m;
   g.resize(n);
   visited.resize(n, false);
   vector<int> d(n, inf);

   for (int i = 0; i < n; i++) {
      cin >> s;
      for (int j = 0; j < m; j++)
         g[i][j] = (s[j] == '0');
   }

   int res = m;
   d[0] = 0;

   for (int i = 0; i < n; i++) {
      int a = -1;

      for (int j = 0; j < n; j++)
         if (not visited[j] and (a == -1 or d[j] < d[a]))
            a = j;

      visited[a] = true;
      res += d[a];

      for (int j = 0; j < n; j++)
         d[j] = min(d[j], dist(a, j));
   }
   cout << res << endl;
}