#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1 << 31 - 1;
const string quack = "quack";

int main() {
   ifstream f("input.txt");
   ofstream out("output.txt");
   ll n, e;
   f >> n;
   ll prev = 0;
   ll ans = -1 << 30;
   for (int i = 0; i < n; i++) {
      f >> e;
      ll dist = min((ll)0, prev - e);
      ans = max(ans, -dist);
      prev = e;
   }
   out << ans;
}

