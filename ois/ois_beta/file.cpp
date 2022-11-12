#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll n, e;
map<ll, ll> m;
bool giorgio = false;

int main() {
   cin >> n;

   for (int i = 0; i < n; i++)
      cin >> e, m[e]++;

   for (auto e: m) {
      if (e.second > 1) {
         if (giorgio) { cout << "YES\n", return 0; }
         else giorgio = true;
      }
   }
   cout << "NO\n";
} 
