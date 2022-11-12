#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll n, m, k;
vi a, b;
vector<vi> memo;

ll dp(int i, int j) {
	if (i == n or j == m) return 0;
	if (memo[i][j] != -1) return memo[i][j];
	return memo[i][j] = max({
		dp(i+1, j),
		dp(i, j+1),
		dp(i+1, j+1) + abs(a[i]-b[j])
	});
}

int main() {
	cin >> n >> m;
	a.resize(n); b.resize(m);
	memo.resize(n, vi(m, -1));
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 0; j < m; j++) cin >> b[j];
	cout << dp(0, 0) << endl;
}

