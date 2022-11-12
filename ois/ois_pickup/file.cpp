#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
const string quack = "quack";

ll a, b, k, len;
string path = "";
bool found = false;
vector<vi> p(301, vi(10));
ll memo[301][301][301];

ll dp(ll l, ll sd, ll sn, ll c) {
	if (sd < 0) return 0;
	if (l == 0) {
		if (sd == 0 and sn == 0 and c == 1) found = true;
		if (sd == 0 and sn == 0) return 1;
		return 0;
	}

	ll r = memo[l][sd][sn];
	if (r and r-10 < c) return r-10;

	ll res = 0;
	for (int i = 1; i <= 9 and not found and c > res; i++) {
		res += dp(l-1, sd-i, (sn + p[l-1][i] + a) % a, c-res);
		if (found) path = to_string(i) + path;
	}

	memo[l][sd][sn] = res+10;
	return res;
}

int main() {
	cin >> a >> b >> k;

	for (int j = 1; j <= 9; j++) p[0][j] = j%a;

	for (int i = 1; i <= b; i++)
		for (int j = 1; j <= 9; j++)
			p[i][j] = (10 * p[i-1][j]) % a;

	for (int l = 0; l <= b and not found; l++) {
		len = l;
		k -= dp(l, b, 0, k);
	}

	cout << path;
}