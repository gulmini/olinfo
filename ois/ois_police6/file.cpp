#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, m, l;
vi v;
vector<pi> h;

int main() {
   cin >> n >> m >> l;
   v.resize(n);
   for (int i = 0; i < n; i++) cin >> v[i];
   for (int i = 0; i < n; i++) {
      h.push_back(pi{v[i]-m, 1});
      h.push_back(pi{v[i]+m, -1});
   }
   sort(h.begin(), h.end());

   n = h.size();
   deque<pi> q;
   for (auto e: h) q.push_back(e);
   ll res = 0;
   while (q.front().first <= 0) {
      res++;
      q.pop_front();
   }
   ll count = res;
   while (not q.empty()) {
      if (q.front().first >= l) break;
      
      count += q.front().second;
      res = min(res, count);
      q.pop_front();
   }
   cout << res;
}