#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef array<ll, 2> i2;
const int inf = INT32_MAX;
const string quack = "quack";

ll n;
vi v;
vector<i2> memo;

ll dp(int i, bool k) {
   if (i < 0) return 0;
   if (memo[i][k] != -1) return memo[i][k];
   ll res = dp(i-1, true) + v[i];
   if (k) res = min(res, dp(i-1, false));
   memo[i][k] = res;
   return res;
}

int main() {
   int n;
   cin >> n;
   v.resize(n);
   memo.resize(n, i2{-1, -1});
   for (int i = 0; i < n; i++) cin >> v[i];
   ll res = dp(n-1, true);
   memo.assign(n, i2{-1, -1});
   cout << min(res, dp(n-1, false));
}