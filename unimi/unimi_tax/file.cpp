#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const string quack = "quack";

int main() {
   ll n, m, a, b;
   double w;
   cin >> n >> m;
   vector<vector<double>> d(n, vector<double>(n, 0));

   for (int i = 0; i < n; i++)
      d[i][i] = 1.0;

   for (int i = 0; i < m; i++) {
      cin >> a >> b >> w;
      d[a][b] = 1.0 - w/1000.0;
   }

   for (int h = 0; h < n; h++)
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
            d[i][j] = max(d[i][j], d[i][h] * d[h][j]);
   
   pi p;
   double res = INFINITY;

   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         if (d[i][j] < res) {
            res = d[i][j];
            p.first = i;
            p.second = j;
         }

   cout << p.first << " " << p.second;
}