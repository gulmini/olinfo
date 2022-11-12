#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const string quack = "quack";

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

	n = v.size();
	int l = -1, r = n-1, lsum = 0, rsum = 0, res = 0;

	while (lsum <= k) {
		l++;
		if (l == n) return n-1;
		lsum += v[l];
	}

	lsum -= v[l]; l--;

	for (; l >= -1; l--) {
		while (lsum + rsum <= k) {
			rsum += v[r];
			r--;
		}
		res = max(res, l - r + n - 1);
		if (l >= 0) lsum -= v[l];
	}
	return res;
}
