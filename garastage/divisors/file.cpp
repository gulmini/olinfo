#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define j n / (n / i) + 1
using namespace std;
const string quack = "quack";

long long compute(long long n) {
   long long res = 0;
   for (long long i = 1; i <= n; i = j) {
      res += (j-i)*(n/i);
   }
   return res;
}