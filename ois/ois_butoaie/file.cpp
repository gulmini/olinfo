#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string quack = "quack";

ll n, k, p, q;
vector<ll> v;

bool check(ll m) {
   ll cf = m * p;
   ll power = m * k;
   for (auto e: v) {
      ll residual = e - cf;
      if (residual <= 0) return true;
      ll days = (residual + q - 1) / q;
      if (days > m or days > power) return false;
      power -= days;
   }
   return true;
}

int main() {
   cin >> n >> k >> p >> q;
   if (p > q) {
      k = n - k;
      swap(p, q);
   }
   q -= p;
   k = n - k;
   v.resize(n);
   for (int i = 0; i < n; i++) cin >> v[i];
   sort(v.rbegin(), v.rend());
   ll l = 0;
   ll r = 1e9;
   while (true) {
      if (l == r and check(l)) {
         cout << l;
         break;
      }
      else {
         ll m = (l+r)/2;
         if (check(m)) r = m;
         else l = m+1;
      }
   }
}