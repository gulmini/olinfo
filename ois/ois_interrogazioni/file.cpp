#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll n, k;

int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   cin >> n >> k;
   vi v(n);
   for (ll i = 0; i < n; i++) cin >> v[i];
   sort(v.begin(), v.end());
   ll delta = INT64_MAX;
   for (ll i = 0; i < n - k + 1; i++) {
      delta = min(delta, v[i+k-1] - v[i]);
   }
   cout << delta << endl;
}