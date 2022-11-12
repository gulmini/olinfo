#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

int n, k, T;
ll L;
vi v;
array<array<ll, 10001>, 2> memo;

inline ll calc(ll t) {
	return (t % (2 * T) < T) ? 0 : T - (t % T);
}

ll iterative() {
	bool b = false;
	for (int c = 0; c <= k; c++) memo[b][c] = v[0];
	for (int i = 1; i <= n; i++) {
		b = not b;
		for (int c = 0; c <= k; c++) {
			ll delta = v[i] - v[i-1];
			memo[b][c] = memo[not b][c] + delta + calc(memo[not b][c]);
			if (c) memo[b][c] = min(
				memo[b][c], 
				memo[not b][c-1] + delta
			);
		}
	}
	return memo[b][k];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k >> T >> L;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	v.push_back(L);
	cout << iterative();
}
