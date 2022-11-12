#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pi;
typedef vector<bool> vb;

void debug_out() { cout << "\n"; }

template <typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
	for (auto e: v) cout << e << " ";
	cout << endl;
	return o;
}
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cout << " " << H;
  debug_out(T...);
}

#ifdef LOCAL
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define init(filename) freopen("in", "r", stdin)
#else
#define dbg(...)
#define init()
#endif

int solve(int n, int k, int* s) {
	vi v;
	for (int i = 0; i <= n; i++) {
		ll c = 0;
		while (i < n and s[i]) {
			c += s[i];
			i++;
		}
		v.push_back(c);
	}
	dbg(v);
	n = v.size();
	int l = -1, r = n-1, lsum = 0, rsum = 0, res = 0;

	while (lsum <= k) {
		l++;
		if (l == n) return n-1;
		lsum += v[l];
	}
	lsum -= v[l]; l--;
	dbg(lsum, l);

	for (; l >= -1; l--) {
		while (lsum + rsum <= k) {
			dbg(r, rsum);
			rsum += v[r];
			r--;
		}
		res = max(res, l - r + n - 1);
		if (l >= 0) lsum -= v[l];
	}
	return res;
}
