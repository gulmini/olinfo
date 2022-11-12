#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
constexpr ll INF = INT64_MAX;
const string quack = "quack";

ll n, k;
array<vi, 2> memo;

int speedrunna(int n, int k, int a, int b) {
	memo[0].assign(k+1, INF); memo[0][0] = 0;
	bool j = true;
	ll w = 1;
	ll v = 1;
	for (int i = 0; i < n; i++) {
		memo[j].assign(k+1, INF);
		j = not j;

		for (int c = 0; c <= k; c++) {
			if (memo[j][c] == INF) continue;

			ll nc = min((ll)k, c+v);
			memo[not j][nc] = min(
				memo[not j][nc],
				memo[j][c] + w
			);

			if (c == k)
				memo[not j][0] = min(
					memo[not j][0],
					memo[j][c]
				);
		}

		w = (w * a) % 1000;
		v = (v * b) % k;
	}
	return *min_element(memo[not j].begin(), memo[not j].end());
}
