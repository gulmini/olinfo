#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
const string quack = "quack";

ll n, m, k, q;
vi v;
vector<vi> memo;

int main() {
  cin >> n;
  v.resize(n);

  for (int i = 0; i < n; i++) cin >> v[i];

  for (int i = 0; i < n; i++) {

    if (i and v[i] == 0 and v[i-1] >= 2)
      v[i-1]--, v[i]++;

    if (i != n-1 and v[i] == 0 and v[i+1] >= 2)
      v[i+1]--, v[i]++;

  }

  cout << count(v.begin(), v.end(), 0) << endl;
}

