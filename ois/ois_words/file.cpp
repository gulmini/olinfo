#include <bits/stdc++.h>
using namespace std;
typedef int_fast64_t ll;
typedef int_fast16_t sint;
typedef pair<sint, sint> pi;
typedef vector<ll> vi;
const ll INF = INT64_MAX/4;
const string quack = "quack";

ll n, l, k;
vector<string> t;
vector<vector<sint>> adj;
unordered_map<int, ll> memo;
vi path;

ll dp(sint i, sint j, ll c) {
   if (i == l-1) return (c == 1) ? -1 : 1;
   int index = 20000*i+j;
   if (memo[index] and c - memo[index] > 0)
      return memo[index];
   ll res = 0;
   for (sint u: adj[j]) {
      ll val = dp(i+1, u, c - res);
      if (val == -1) {
         path.push_back(u);
         if (i == 0) path.push_back(j);
         return -1;
      }
      res += val;
   }
   memo[index] = res;
   return res;
}

int main() {
   ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   cin >> k >> l >> n;
   l -= 2;
   t.resize(n);
   adj.resize(n);
   for (int i = 0; i < n; i++) cin >> t[i];
   sort(t.begin(), t.end());
   for (int i = 0; i < n; i++) {
      string s = t[i];
      string bi = ""; bi += s[1]; bi += s[2];
      int low = lower_bound(t.begin(), t.end(), bi) - t.begin();
      bi += 'z'+1;
      int high = lower_bound(t.begin(), t.end(), bi) - t.begin();
      for (int j = low; j != high; j++)
         adj[i].push_back(j);
   }
   for (sint i = 0; i < n; i++) {
      ll val = dp(0, i, k);
      if (val == -1) break;
      else k -= val;
   }
   cout << t[path.back()]; path.pop_back();
   while (not path.empty()) {
      cout << t[path.back()][2];
      path.pop_back();
   }
}