#include <bits/stdc++.h>
using namespace std;
const string quack = "quack";

int n, e;
vector<int> v, memo;

int solve(int i, int layer) {
   if (i + layer + 1 >= n) {
      memo[i] = v[i];
   }
   else if (memo[i] == -1) {
      int left = solve(i + layer + 1, layer+1);
      int right = solve(i + layer + 2, layer+1);
      memo[i] = v[i] + max(left, right);
   }
   return memo[i];
}

int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   cin >> n;
   n = n * (n+1) / 2;
   memo.resize(n, -1);
   v.resize(n);
   for (int i = 0; i < n; i++) cin >> v[i];
   cout << solve(0, 0) << endl;
}
