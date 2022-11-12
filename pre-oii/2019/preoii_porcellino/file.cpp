#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string quack = "quack";

bool chiedi(int x);

int indovina() {
  chiedi(0);
  int x = 0, y, res = 0;

  for (int i = 0; i < 31; i++) {
    y = x + (1ll << i);
    if (chiedi(y)) res += (1ll << i);
    x = y;
  }

  return res;
}

