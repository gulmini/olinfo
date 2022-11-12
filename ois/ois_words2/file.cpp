#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const ll MOD = 1e9+7;
const string quack = "quack";

string s;
vi p;
vi v;

int main() {
   ll res = 0;
   cin >> s;
   int n = s.size();
   v.resize(n);
   p.resize(n); p[0] = 1;
   for (int i = 1; i < n; i++) {
      p[i] = (26 * p[i-1]) % MOD;
   }
   for (int i = n-1; i >= 0; i--) {
      v[i] = s[i] - 'a' + 1;
   }
   reverse(v.begin(), v.end());
   for (int i = 0; i < n; i++) {
      res += (v[i] * p[i]) % MOD;
      res %= MOD;
   }
   cout << res-1;
}