#include <bits/stdc++.h>
using namespace std;
const string quack = "quack";

ll n, q, d, x, y, z;
vector<double> stars;

int main() {
   freopen ("output.txt", "w", stdout);
   freopen ("input.txt", "r", stdin);
   ios::sync_with_stdio(false);
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> x >> y >> z;
      stars.push_back(sqrt(x*x + y*y + z*z));
   }
   sort(stars.begin(), stars.end());
   cin >> q;
   while (q--) {
      cin >> d;
      cout << upper_bound(stars.begin(), stars.end(), (double)d) - stars.begin() << '\n';
   }
}
