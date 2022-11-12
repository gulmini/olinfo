#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

ll n, res = 0;
vi v;

ll conta(int n, vector<int> v) {
	stack<ll> mins, maxs;
	vi br(n), bl(n), sr(n), sl(n);

	for (int i = 0; i < n; i++) {
		while (not maxs.empty() and v[maxs.top()] <= v[i]) maxs.pop();
		while (not mins.empty() and v[mins.top()] >= v[i]) mins.pop();
		bl[i] = (maxs.empty()) ? -1 : maxs.top();
		sl[i] = (mins.empty()) ? -1 : mins.top();
		maxs.push(i); mins.push(i);
	}

	while (not mins.empty()) mins.pop();
	while (not maxs.empty()) maxs.pop();

	for (int i = n-1; i >= 0; i--) {
		while (not maxs.empty() and v[maxs.top()] <= v[i]) maxs.pop();
		while (not mins.empty() and v[mins.top()] >= v[i]) mins.pop();
		br[i] = (maxs.empty()) ? n : maxs.top();
		sr[i] = (mins.empty()) ? n : mins.top();
		maxs.push(i); mins.push(i);
	}

	ll z, w, res = 0;
	for (ll i = 0; i < n; i++) {
		ll l = bl[i], r = br[i];
		ll x = sl[i], y = i;

		while (x > l and y < r) {
			x = sl[x];
			y = sr[y];
		}

		if (x <= l)
			for (ll x = sl[i]; x > l; x = sl[x]) {
				z = max(sl[x], l);
				w = min(sr[x], r);
				res += (x - z) * (w - i);
			}
		else {
			for (ll y = i; y < r; y = sr[y]) {
				z = max(sl[y], l);
				w = min(sr[y], r);
				res += (z - l) * (w - y);
			}
		}
	}
	return res;
}

