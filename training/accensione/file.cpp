#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector<int> vi;
const string quack = "quack";

void Accendi(int n, int start[], int res[]) {
   for (int i = n; i > 0; i--) {
      for (int j = 2*i; j <= n; j += i)
         start[i] = start[i] ^ res[j];
      res[i] = (not start[i]);
   }
}
