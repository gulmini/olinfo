#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
void debug_out() { cout << "\n"; }
template <typename T> ostream& operator<<(ostream& o, vector<T>& v) { for (auto e: v) cout << e << " "; cout << endl; return o; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cout << " " << H; debug_out(T...); }

ll n, m, k, q;
vi v;
ll l, r;

int main() {
  cin >> n >> l >> r;
  ll k = (n + r - 1) / r;
  cout << (k * l <= n ? k : -1) << endl;
}

