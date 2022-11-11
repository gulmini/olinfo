#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const ll INF = INT64_MAX / 4;
const string quack = "quack";

struct Candle {
   ll a, b, index;
   bool operator<(const Candle &other) const {
      if (a != other.a) return a < other.a;
      return index < other.index;
   }
   bool operator>(const Candle &other) const {
      if (a != other.a) return a > other.a;
      return index < other.index;
   }
};

void brucia(int n, vector<int> &M, vector<int> &B, vi &d) {
   vector<vector<pi>> adj (n);
   vector<Candle> candles;
   vector<bool> visited(n, false);
   d.assign(n, INF); d[0] = 0;
   for (int i = 0; i < n; i++) {
      candles.push_back(Candle {M[i], B[i], i});
   }
   sort(candles.begin(), candles.end());
   stack<Candle> s;
   for (Candle &c: candles) {
      while (not s.empty() and c.b <= s.top().a) {
         Candle u = s.top();
         adj[c.index].push_back(pi(c.a - u.a, u.index));
         if (c.a - u.a == 0) 
            adj[u.index].push_back(pi(0, c.index));
         s.pop();
      }
      s.push(c);
   }
   while (not s.empty()) s.pop();
   sort(candles.begin(), candles.end(), greater<Candle>());
   for (Candle &c: candles) {
      while (not s.empty() and c.b >= s.top().a) {
         Candle u = s.top();
         adj[c.index].push_back(pi(u.a - c.a, u.index));
         if (u.a - c.a == 0) 
            adj[u.index].push_back(pi(0, c.index));
         s.pop();
      }
      s.push(c);
   }
   priority_queue<pi, vector<pi>, greater<pi>> q;
   q.push({0, 0});
   while (not q.empty()) {
      ll a = q.top().second; q.pop();
      visited[a] = true;
      for (auto [w, b]: adj[a]) {
         if (visited[b]) continue;
         if (d[a] + w < d[b]) {
            d[b] = d[a] + w;
            q.push(pi(d[b], b));
         }
      }
   }
   for (auto &e: d)
      if (e >= INF) e = -1;
}

